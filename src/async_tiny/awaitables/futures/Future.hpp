#pragma once

#include "async_tiny/awaitables/futures/Future.decl.hpp"


namespace async_tiny
{
namespace awaitables
{
namespace futures
{
	template <typename ResultType> void Future<ResultType>::set_result(ResultType&& result)
	{
		set_result(result);
	}
	
	template <typename ResultType> void Future<ResultType>::set_result(ResultType& result)
	{
		StateUtility::_state = async_tiny::StateType::TERMINATED;
		ResultContainer<ResultType>::_result = result;
	}
	
	inline void Future<void>::set_result(void)
	{
		StateUtility::_state = async_tiny::StateType::TERMINATED;
	}
}
}
}
