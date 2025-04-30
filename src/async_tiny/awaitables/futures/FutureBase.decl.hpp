#pragma once

#include "async_tiny/awaitables/futures/AbstractFuture.decl.hpp"
#include "async_tiny/awaitables/futures/FutureBase.fwd.hpp"
#include "async_tiny/utilities/StateUtility.decl.hpp"


namespace async_tiny
{
namespace awaitables
{
namespace futures
{
	class FutureBase : public AbstractFuture, public utilities::StateUtility
	{
		public:
		
		bool _await(void) override;
	};
}
}
}
