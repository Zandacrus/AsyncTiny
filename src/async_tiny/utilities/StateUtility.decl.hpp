#pragma once

#include "async_tiny/utilities/StateUtility.fwd.hpp"

extern "C"
{
#include <stdint.h>
}


namespace async_tiny
{
	// The states of an awaitable 
	enum class StateType : uint8_t
	{
		// When the awaitable is not awaited for once (or, 
		// not scheduled in case of a task) [initial state] 
		NOT_INITIATED, 
		SUSPENDED,     // When the awaitable is not being executed 
		NOT_SUSPENDED, // When the awaitable is being executed 
		TERMINATED     // When the awaitable has finished execution 
	};
	
namespace utilities
{
	// An awaitable might not need any state. Hence 
	// this class can be inherited if state is needed. 
	class StateUtility
	{
		protected:
		
		StateType _state = StateType::NOT_INITIATED;
		
		public:
		
		void terminate(void);
		
		void reset(void);
		
		bool is_initiated(void);
		
		bool is_suspended(void);
		
		bool is_terminated(void);
	};
}
}
