#pragma once

#include "async_tiny/utilities/CoroutineUtility.decl.hpp"


namespace async_tiny
{
namespace utilities
{
	inline void CoroutineUtility::terminate(void)
	{
		stage_ = 255;
		StateUtility::terminate();
	}
	
	inline void CoroutineUtility::reset(void)
	{
		stage_ = 0;
		StateUtility::reset();
	}
}
}
