#pragma once

#include "async_tiny/awaitables/futures/AbstractFuture.decl.hpp"
#include "async_tiny/awaitables/tasks/Task.decl.hpp"
#include "async_tiny/awaitables/tasks/TaskBase.decl.hpp"
#include "async_tiny/EventLoop.fwd.hpp"
#include "async_tiny/time/Time.decl.hpp"
#include "async_tiny/utilities/CoroutineUtility.decl.hpp"

extern "C"
{
#include <stdint.h>
}


namespace async_tiny
{
	class EventLoop
	{
		public:
		
		static uint8_t _taskLimit;
		static uint8_t _currentTaskID;
		
		// Array of pointers to tasks of size _taskLimit. Whenever a task is 
		// scheduled a pointer to the task is assigned to a null element of 
		// this array. The index of the element in this array is same as the id 
		// of that task. Initial value of all elements of this array is nullptr. 
		static awaitables::tasks::TaskBase** _tasks;
		
		// If _tasks[i] points to a task then _coroutines[i] points to the 
		// coroutine associated with the task. Initial value of all elements 
		// of this array is nullptr. 
		static utilities::CoroutineUtility** _coroutines;
		
		// If _tasks[i] points to a task and the task suspends on a future 
		// then _suspensionFutures[i] points to that future. Initial value 
		// of all elements of this array is nullptr. 
		static awaitables::futures::AbstractFuture** _suspensionFutures;
		
		// If _tasks[i] points to a task then when the task is suspended 
		// using CO_SLEEP macro _sleepTimers[i] is assigned the wake-up 
		// time. Initial value of all elements of this array is 0. 
		static time::Time* _sleepTimers;
		
		// Array of size _taskLimit. Used as a stack to allot a null position 
		// in the _tasks array to a scheduled task. _availableTaskSlot acts 
		// as the top element of the stack. The elements in the stack are indices 
		// of _tasks array at which the element in _tasks array is null. 
		static uint8_t*	_availableTaskStack;
		static uint8_t  _availableTaskSlot;
		
		// For example, initially, 
		// [nullptr, nullptr, ..., nullptr] 	-- _tasks 
		// [0, 1, 2, 3, 4, ..., _taskLimit-1] 	-- _availableTaskStack 
		// _availableTaskSlot = 0 
		
		// If task0, task1, task2 is scheduled, 
		// [task0, task1, task2, nullptr, nullptr, ..., nullptr] 	-- _tasks 
		// [0, 1, 2, 3, 4, ..., _taskLimit-1] 						-- _availableTaskStack 
		// _availableTaskSlot = 3 
		
		// If task1 terminates, 
		// [task0, nullptr, task2, nullptr, nullptr, ..., nullptr] 	-- _tasks 
		// [0, 1, 1, 3, 4, ..., _taskLimit-1] 						-- _availableTaskStack 
		// _availableTaskSlot = 2 
		
		// If task2 terminates, 
		// [task0, nullptr, nullptr, nullptr, ..., nullptr] 	-- _tasks 
		// [0, 2, 1, 3, 4, ..., _taskLimit-1] 					-- _availableTaskStack 
		// _availableTaskSlot = 1 
		
		// If task3 is scheduled, 
		// [task0, task3, nullptr, nullptr, ..., nullptr] 	-- _tasks 
		// [0, 2,  1, 3, 4, ..., _taskLimit-1] 			-- _availableTaskStack 
		// _availableTaskSlot = 2 
		
		// Awaits the associated coroutine and returns true only if the 
		// associated coroutine has terminated and so the task must terminate. 
		static bool _execute_current_task(void);
		
		// Removes the task with id = taskID from _tasks list and removes its access to 
		// the shared resources. This method is called after a task has terminated.
		static void _remove_task(uint8_t taskID);
		
		static void _remove_all_tasks(void);
		
		public:
		
		// Returns true if scheduling is successful otherwise false. 
		template <typename CoroType> static bool schedule_task(awaitables::tasks::Task_C<CoroType>&, CoroType&, const typename awaitables::tasks::Task_C<CoroType>::ArgumentType&);
		template <typename CoroType> static bool schedule_task(awaitables::tasks::Task_C<CoroType>&, CoroType&, const typename awaitables::tasks::Task_C<CoroType>::ArgumentType&&);
		template <typename CoroType> static bool schedule_task(awaitables::tasks::Task_C<CoroType>&, CoroType&);
		
		// Scheduling a task may fail because of - 
		// 1. The task is already scheduled (i.e., id of the task is not equal to 255). 
		// 2. There are already _taskLimit no. of running tasks. 
		
		// Returns true when main task is completed (if MF_WAIT_FOR_ALL_TASKS == false) 
		// or all scheduled tasks are completed  (if MF_WAIT_FOR_ALL_TASKS == true)
		static bool run_loop_once(void);
		
		static bool set_task_limit(uint8_t taskLimit);
	};
}
