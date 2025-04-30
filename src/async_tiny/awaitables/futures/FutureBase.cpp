#define PREVENT_FEATURE_MODIFICATION

#include "async_tiny/awaitables/futures/AbstractFuture.hpp"
#include "async_tiny/awaitables/futures/FutureBase.hpp"
#include "async_tiny/utilities/StateUtility.hpp"


namespace async_tiny
{
namespace awaitables
{
namespace futures
{
	bool FutureBase::_await(void)
	{
		if (StateUtility::is_terminated()) return true;
		
		// In case it is awaited in multiple tasks 
		// _set_suspension_future() must be called 
		// when it is awaited in each task. 
		AbstractFuture::_set_suspension_future();
		return false;
	}
}
}
}
