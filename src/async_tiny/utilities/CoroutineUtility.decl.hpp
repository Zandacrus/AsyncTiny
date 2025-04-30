#pragma once

#include "async_tiny/EventLoop.fwd.hpp"
#include "async_tiny/utilities/CoroutineUtility.fwd.hpp"
#include "async_tiny/utilities/StateUtility.decl.hpp"

extern "C"
{
#include <stdint.h>
}


namespace async_tiny
{
namespace utilities
{
	// A non-templated base class is useful to store references 
	// to different (templated) coroutines [used in EventLoop class]
	class CoroutineUtility : public async_tiny::utilities::StateUtility
	{
		protected:
		
		// A coroutine may await one or more awaitables. If a coroutine 
		// gets suspended after awaiting an awaitable, it must resume at 
		// the same position later. This position is marked as a stage. 
		// Wherever a coroutine awaits an awaitable a stage is marked. 
		// [add reference to how stage is marked]
		// The stage_ member stores the last stage from where a coroutine 
		// suspended. When a coroutine resumes, control is transferred to 
		// this stage using some jumping mechanism. 
		// [add reference to jumping mechanism]
		uint8_t stage_ = 0;
		
		public:
		
		void terminate(void);
		
		// A coroutine can be reused by resetting it 
		virtual void reset(void) = 0;
		
		// Protected member StateUtility::_state is modified
		// inside EventLoop::_execute_current_task method. 
		friend class async_tiny::EventLoop;
	};
}
}
