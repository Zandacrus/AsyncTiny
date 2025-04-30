#pragma once

#include "async_tiny/awaitables/tasks/TaskBase.decl.hpp"


namespace async_tiny
{
namespace awaitables
{
namespace tasks
{
	inline bool TaskBase::reset(bool forceTerminate)
	{
		if (_id != 255)
		{
			// the task has access to the allotted resources 
			if (!forceTerminate) return false;
			EventLoop::_remove_task(_id);
		}
		StateUtility::reset();
		return true;
	}
}
}
}
