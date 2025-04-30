#pragma once

#include "async_tiny/awaitables/futures/Future.fwd.hpp"
#include "async_tiny/awaitables/futures/FutureBase.decl.hpp"
#include "async_tiny/Containers.hpp"


namespace async_tiny
{
namespace awaitables
{
namespace futures
{
	template <typename ResultType> class Future : public FutureBase, protected ResultContainer<ResultType>
	{
		public:
		
		// Future is marked TERMINATED only when 
		// set_result method is invoked. 
		void set_result(ResultType&&);
		
		void set_result(ResultType&);
	};
	
	template <> class Future<void> : public FutureBase, protected ResultContainer<void>
	{
		public:
		
		void set_result(void);
	};
}
}
}
