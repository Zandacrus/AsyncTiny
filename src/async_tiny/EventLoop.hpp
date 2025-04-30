#pragma once

#include "async_tiny/awaitables/coroutines/CoroutineBase.decl.hpp"
#include "async_tiny/awaitables/tasks/Task.decl.hpp"
#include "async_tiny/EventLoop.decl.hpp"
#include "async_tiny/StdImplementation.hpp"


namespace async_tiny
{
	template <typename CoroType> bool EventLoop::schedule_task(
		awaitables::tasks::Task_C<CoroType>& task, 
		CoroType& coro, 
		const typename awaitables::tasks::Task_C<CoroType>::ArgumentType& args
	)
	{
		bool scheduled = schedule_task(task, coro);
		if (scheduled) task._args = args;
		return scheduled;
	}
	
	template <typename CoroType> bool EventLoop::schedule_task(
		awaitables::tasks::Task_C<CoroType>& task, 
		CoroType& coro, 
		const typename awaitables::tasks::Task_C<CoroType>::ArgumentType&& args
	)
	{
		return schedule_task(task, coro, args);
	}
	
	template <typename CoroType> bool EventLoop::schedule_task(
		awaitables::tasks::Task_C<CoroType>& task, 
		CoroType& coro
	)
	{
		static_assert(awaitables::coroutines::is_coroutine<CoroType>());
		
		if (
			task._id != 255 // task is already scheduled
			|| 
			_availableTaskSlot == _taskLimit // total tasks' limit reached 
		) return false;
		
		// Popping top element of the stack 
		task._id = _availableTaskStack[_availableTaskSlot++];
		
		task._state = async_tiny::StateType::SUSPENDED;
		_tasks[task._id] = &task;
		coro.reset();
		_coroutines[task._id] = &coro;
		
		return true;
	}
	
	#include "async_tiny/macros/FeatureOptions/DisableCoSleep.inc"
	#include "async_tiny/macros/FeatureOptions/DisableSuspensionOnFuture.inc"
	
	inline bool EventLoop::_execute_current_task(void)
	{
		if (
			// Defined in async_tiny/macros/FeatureOptions/DisableCoSleep.inc 
			SLEEP_CONDITION_ 
			|| 
			// Defined in async_tiny/macros/FeatureOptions/DisableSuspensionOnFuture.inc 
			SUSPEND_ON_FUTURE_CONDITION_ 
		) return false;
		
		#if (MF_DISABLE_CO_SLEEP == false)
		_sleepTimers[_currentTaskID].reset();
		#endif
		
		_tasks[_currentTaskID]->_state = async_tiny::StateType::NOT_SUSPENDED;
		_coroutines[_currentTaskID]->_state = async_tiny::StateType::NOT_SUSPENDED;
		
		if (_tasks[_currentTaskID]->_await_coroutine())
		{
			_coroutines[_currentTaskID]->_state = async_tiny::StateType::TERMINATED;
			_tasks[_currentTaskID]->_state = async_tiny::StateType::TERMINATED;
			return true;
		}
		
		_coroutines[_currentTaskID]->_state = async_tiny::StateType::SUSPENDED;
		_tasks[_currentTaskID]->_state = async_tiny::StateType::SUSPENDED;
		return false;
	}
	
	inline void EventLoop::_remove_task(uint8_t taskID)
	{
		_coroutines[taskID] = nullptr;
		_tasks[taskID]->_id = 255;
		_tasks[taskID] = nullptr;
		
		#if (MF_DISABLE_SUSPENSION_ON_FUTURE == false)
		_suspensionFutures[taskID] = nullptr;
		#endif
		
		#if (MF_DISABLE_CO_SLEEP == false)
		_sleepTimers[taskID].reset();
		#endif
		
		// Pushing _currentTaskID to the top of the stack 
		_availableTaskStack[--_availableTaskSlot] = taskID;
	}
	
	inline void EventLoop::_remove_all_tasks(void)
	{
		for(_currentTaskID = 0; _currentTaskID < _taskLimit; _currentTaskID++)
		{
			if (_tasks[_currentTaskID]!=nullptr) _remove_task(_currentTaskID);
		}
	}
	
	#include "async_tiny/macros/FeatureOptions/WaitForAllTasks.inc"
	
	inline bool EventLoop::run_loop_once(void)
	{
		// Defined in async_tiny/macros/FeatureOptions/WaitForAllTasks.inc
		EXECUTE_TASK0_();
		
		for (
			// Defined in async_tiny/macros/FeatureOptions/WaitForAllTasks.inc
			_currentTaskID = CURRENT_TASK_ID_INITIAL_VALUE_; 
			_currentTaskID < _taskLimit; 
			_currentTaskID++
		)
		{
			if (_tasks[_currentTaskID]!=nullptr && _execute_current_task())
			{
				_remove_task(_currentTaskID);
			}
		}
		
		// _availableTaskSlot will be 0 only when all scheduled 
		// tasks are completed or no task is scheduled 
		return _availableTaskSlot==0;
	}
	
	inline bool EventLoop::set_task_limit(uint8_t taskLimit)
	{
		bool alreadySet = _taskLimit>0, validLimit = taskLimit>0, 
		nullCheck = _availableTaskStack==nullptr || _tasks==nullptr || _coroutines==nullptr || _suspensionFutures==nullptr || _sleepTimers==nullptr;
		if (alreadySet || !validLimit || !nullCheck) return false;
		
		_taskLimit = taskLimit;
		_availableTaskStack = new uint8_t[taskLimit]();
		for(int i=0; i<taskLimit; i++) _availableTaskStack[i] = i;
		
		_tasks = new awaitables::tasks::TaskBase*[taskLimit]();
		_coroutines = new utilities::CoroutineUtility*[taskLimit]();
		_suspensionFutures = new awaitables::futures::AbstractFuture*[taskLimit]();
		_sleepTimers = new time::Time[taskLimit]();
		
		return true;
	}
}
