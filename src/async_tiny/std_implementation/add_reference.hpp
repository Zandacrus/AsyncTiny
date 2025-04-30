#pragma once

namespace async_tiny
{
namespace std_implementation
{
	// reference - https://en.cppreference.com/w/cpp/types/add_reference
	namespace internal
	{
		template<class T>
		struct type_identity { using type = T; }; // or use std::type_identity (since C++20)
	
		template<class T> // Note that “cv void&” is a substitution failure
		auto try_add_lvalue_reference(int) -> type_identity<T&>;
		template<class T> // Handle T = cv void case
		auto try_add_lvalue_reference(...) -> type_identity<T>;
	
		template<class T>
		auto try_add_rvalue_reference(int) -> type_identity<T&&>;
		template<class T>
		auto try_add_rvalue_reference(...) -> type_identity<T>;
	}
	
	template<class T>
	struct add_lvalue_reference
		: decltype(internal::try_add_lvalue_reference<T>(0)) {};
	
	template<class T>
	struct add_rvalue_reference
		: decltype(internal::try_add_rvalue_reference<T>(0)) {};
}
}