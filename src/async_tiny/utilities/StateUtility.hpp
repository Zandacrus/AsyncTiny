#pragma once

#include "async_tiny/utilities/StateUtility.decl.hpp"


namespace async_tiny
{
namespace utilities
{
	inline void StateUtility::terminate(void)
	{
		_state = StateType::TERMINATED;
	}
	
	inline void StateUtility::reset(void)
	{
		_state = StateType::NOT_INITIATED;
	}
	
	inline bool StateUtility::is_initiated(void)
	{
		return _state != StateType::NOT_INITIATED;
	}
	
	inline bool StateUtility::is_suspended(void)
	{
		return _state == StateType::SUSPENDED;
	}
	
	inline bool StateUtility::is_terminated(void)
	{
		return _state == StateType::TERMINATED;
	}
}
}
