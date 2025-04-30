#pragma once

#include "async_tiny/awaitables/futures/AbstractFuture.decl.hpp"
#include "async_tiny/EventLoop.decl.hpp"


namespace async_tiny
{
namespace awaitables
{
namespace futures
{
	inline void AbstractFuture::_set_suspension_future(void)
	{
		// This method is only called while awaiting a future. Since a future is awaited either 
		// inside a coroutine or a task and a coroutine is awaited either inside a task or another 
		// coroutine, this method is always called from inside the task currently executed. 
		async_tiny::EventLoop::_suspensionFutures[async_tiny::EventLoop::_currentTaskID] = this;
	}
}
}
}
