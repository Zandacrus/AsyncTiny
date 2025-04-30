#pragma once

#include "async_tiny/awaitables/Awaitable.decl.hpp"
#include "async_tiny/awaitables/coroutines/CoroutineBase.fwd.hpp"
#include "async_tiny/utilities/CoroutineUtility.decl.hpp"

namespace async_tiny
{
namespace awaitables
{
namespace coroutines
{
	// Any class that inherits any specialization of CoroutineBase class template, 
	// and, overrides the _await method of Awaitable and reset method of 
	// CoroutineUtility becomes a Coroutine class.
	template <bool doesReturn, bool hasArg> class CoroutineBase : public Awaitable<doesReturn, hasArg>, public utilities::CoroutineUtility {};
	
	template <class CoroType> constexpr bool is_coroutine()
	{
		return std_implementation::is_base_of<decltype(get_coroutine_base((CoroType*)0)), CoroType>::value;
	}
	
	template <bool doesReturn, bool hasArg> CoroutineBase<doesReturn, hasArg> get_coroutine_base(CoroutineBase<doesReturn, hasArg>*)
	{
		static_assert(false, "get_coroutine_base not allowed in an evaluated context");
	}
}
}
}
