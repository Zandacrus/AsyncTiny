#pragma once

#include "async_tiny/awaitables/futures/FutureBase.decl.hpp"
#include "async_tiny/awaitables/tasks/TaskBase.fwd.hpp"
#include "async_tiny/EventLoop.fwd.hpp"
#include "async_tiny/utilities/StateUtility.decl.hpp"


namespace async_tiny
{
namespace awaitables
{
namespace tasks
{
	class TaskBase : public futures::FutureBase
	{
		protected:
		
		// Whenever a task is scheduled in the EventLoop it is assigned an id. 
		// When a task is not scheduled in the EventLoop (state - NOT_INITIATED) 
		// or is removed from the EventLoop (state - TERMINATED) the id of the task 
		// is 255. The id assigned to the task is used to access some resources 
		// [defined in EventLoop class] alloted to the task. The task needs these 
		// resources only while execution, hence, these resources are reused by allotting
		// them to different tasks at different times. 
		uint8_t _id = 255;
		
		// Awaiting the coroutine associated with the task in _await method is necessary.
		// This method is called in _await method and is overriden by subclasses of TaskBase 
		// where the signature of the _await method of coroutine is known. 
		virtual bool _await_coroutine(void) = 0;
		
		public:
		
		// A task can be reused after successfully resetting it. 
		// Returns true if the task has terminated and is removed from the EventLoop. 
		bool reset(void);
		bool reset(bool forceTerminate);
		
		// Protected member TaskBase::_id is accessed
		// inside EventLoop::_remove_task method.
		friend class async_tiny::EventLoop;
	};
}
}
}
