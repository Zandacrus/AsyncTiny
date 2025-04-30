#pragma once

#include "async_tiny/awaitables/coroutines/BasicCoroutine.fwd.hpp"
#include "async_tiny/awaitables/coroutines/CoroutineBase.decl.hpp"
#include "async_tiny/utilities/CoroutineUtility.decl.hpp"

namespace async_tiny
{
namespace awaitables
{
namespace coroutines
{
	template <typename RetType, typename ArgType> class BasicCoroutine : public CoroutineBase<true, true>
	{
		public:
		using ReturnType = async_tiny::std_implementation::remove_reference_t<RetType>;
		using ArgumentType = async_tiny::std_implementation::remove_reference_t<ArgType>;
		using CoroutineBase = CoroutineBase;
		
		virtual bool _await(ReturnType&, ArgumentType&) = 0;
		
		bool _await(void* result, void* arg) final
		{
			return _await(*static_cast<ReturnType*>(result), *static_cast<ArgumentType*>(arg));
		}
		
		bool _await(ReturnType& result, ArgumentType&& arg)
		{
			return _await(result, arg);
		}
	};
	
	template <typename RetType> class BasicCoroutine<RetType, void> : public CoroutineBase<true, false>
	{
		public:
		using ReturnType = async_tiny::std_implementation::remove_reference_t<RetType>;
		using ArgumentType = void;
		using CoroutineBase = CoroutineBase;
		using Awaitable::_await;
		
		virtual bool _await(ReturnType&) = 0;
		
		bool _await(void* result) final
		{
			return _await(*static_cast<ReturnType*>(result));
		}
	};
	
	template <typename ArgType> class BasicCoroutine<void, ArgType> : public CoroutineBase<false, true>
	{
		public:
		using ReturnType = void;
		using ArgumentType = async_tiny::std_implementation::remove_reference_t<ArgType>;
		using CoroutineBase = CoroutineBase;
		using Awaitable::_await;
		
		virtual bool _await(ArgumentType&) = 0;
		
		bool _await(void* arg) final
		{
			return _await(*static_cast<ArgumentType*>(arg));
		}
		
		bool _await(ArgumentType&& arg)
		{
			return _await(arg);
		}
	};
	
	template <> class BasicCoroutine<void, void> : public CoroutineBase<false, false>
	{
		public:
		using ReturnType = void;
		using ArgumentType = void;
		using CoroutineBase = CoroutineBase;
	};
}
}
}
