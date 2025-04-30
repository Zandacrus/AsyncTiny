#pragma once

#include "async_tiny/awaitables/tasks/Task.decl.hpp"
#include "async_tiny/StdImplementation.hpp"


namespace async_tiny
{
namespace awaitables
{
namespace tasks
{
	#include "async_tiny/macros/FeatureOptions/DisableIfConstexpr.inc"
	
	template <typename RetType, typename ArgType> bool Task<RetType, ArgType>::_await_coroutine(void)
	{
		// Defined in async_tiny/macros/FeatureOptions/DisableIfConstexpr.inc
		AT_IF_CONSTEXPR_ (async_tiny::std_implementation::is_same<Task::ReturnType, void>::value)
		{
			AT_IF_CONSTEXPR_ (async_tiny::std_implementation::is_same<Task::ArgumentType, void>::value)
			{
				return static_cast<coroutines::CoroutineBase<false, false>*>(
					async_tiny::EventLoop::_coroutines[TaskBase::_id]
				)->_await();
			}
			else
			{
				return static_cast<coroutines::CoroutineBase<false, true>*>(
					async_tiny::EventLoop::_coroutines[TaskBase::_id]
				)->_await(
					&static_cast<Task::ArgumentType&>(Task::ArgContainer::_args)
				);
			}
		}
		else
		{
			AT_IF_CONSTEXPR_ (async_tiny::std_implementation::is_same<Task::ArgumentType, void>::value)
			{
				return static_cast<coroutines::CoroutineBase<true, false>*>(
					async_tiny::EventLoop::_coroutines[TaskBase::_id]
				)->_await(
					&static_cast<Task::ReturnType&>(Task::ResultContainer::_result)
				);
			}
			else
			{
				return static_cast<coroutines::CoroutineBase<true, true>*>(
					async_tiny::EventLoop::_coroutines[TaskBase::_id]
				)->_await(
					&static_cast<Task::ReturnType&>(Task::ResultContainer::_result), 
					&static_cast<Task::ArgumentType&>(Task::ArgContainer::_args)
				);
			}
		}
	}
	
	template <typename RetType, typename ArgType> RetType Task<RetType, ArgType>::get_result()
	{
		return ResultContainer<RetType>::_result;
	}
}
}
}
