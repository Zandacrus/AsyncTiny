#pragma once

#include "async_tiny/awaitables/tasks/Task.fwd.hpp"
#include "async_tiny/awaitables/tasks/TaskBase.decl.hpp"
#include "async_tiny/Containers.hpp"
#include "async_tiny/StdImplementation.hpp"


namespace async_tiny
{
namespace awaitables
{
namespace tasks
{
	template <typename RetType, typename ArgType> class Task : 
		public TaskBase, 
		protected ResultContainer<
			std_implementation::remove_cvref_t<RetType>
		>, 
		protected ArgContainer<
			std_implementation::remove_cvref_t<ArgType>
		>
	{
		protected:
		
		bool _await_coroutine(void) override;
		
		public:
		
		using ReturnType = 
			async_tiny::std_implementation::remove_cvref_t<RetType>;
		using ArgumentType = 
			async_tiny::std_implementation::remove_cvref_t<ArgType>;
		
		RetType get_result();
		
		// Protected member ArgContainer::_args is accessed
		// inside EventLoop::schedule_task method.
		friend class async_tiny::EventLoop;
	};
	
	template <typename CoroutineType> 
	using Task_C = Task<
		typename CoroutineType::ReturnType,
		typename CoroutineType::ArgumentType
	>;
}
}
}
