#pragma once

#include "async_tiny/awaitables/Awaitable.fwd.hpp"


namespace async_tiny
{
namespace awaitables
{
	template <bool doesReturn, bool hasArg> class Awaitable
	{
		public:
		
		// Awaiting an awaitable means calling the _await method. 
		// Should return true if the awaitable has finished execution 
		// otherwise false. Since different types of awaitable have 
		// different behaviours, _await method is overriden in 
		// subclasses of Awaitable class. 
		virtual bool _await(void* result, void* arg) = 0;
	};
	
	template <> class Awaitable<true, false>
	{
		public:
		
		virtual bool _await(void* result) = 0;
	};
	
	template <> class Awaitable<false, true>
	{
		public:
		
		virtual bool _await(void* arg) = 0;
	};
	
	template <> class Awaitable<false, false>
	{
		public:
		
		virtual bool _await(void) = 0;
	};
}
}
