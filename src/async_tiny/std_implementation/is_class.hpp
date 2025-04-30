#pragma once

#include "async_tiny/std_implementation/integral_constant.hpp"
#include "async_tiny/std_implementation/is_union.hpp"


namespace async_tiny
{
namespace std_implementation
{
	// reference - https://en.cppreference.com/w/cpp/types/is_class
	namespace internal
	{
		template<class T>
		std_implementation::integral_constant<bool, !std_implementation::is_union<T>::value> test(int T::*);
	
		template<class>
		std_implementation::false_type test(...);
	}
	template<class T>
	struct is_class : decltype(internal::test<T>(nullptr)) {};
}
}