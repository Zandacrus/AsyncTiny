#pragma once

#include "async_tiny/awaitables/Awaitable.decl.hpp"
#include "async_tiny/awaitables/futures/AbstractFuture.fwd.hpp"


namespace async_tiny
{
namespace awaitables
{
namespace futures
{
	// A base class for both stateless and stateful (templated) futures 
	class AbstractFuture : public Awaitable<false, false>
	{
		protected:
		
		// Awaiting a future in a coroutine results in suspension of both the 
		// coroutine and the task associated with the coroutine. This method marks 
		// (or points) the awaited future as the suspension future of the task. 
		// This method should be called on the future object when it is awaited 
		// in a task for the first time. 
		void _set_suspension_future(void);
	};
}
}
}
