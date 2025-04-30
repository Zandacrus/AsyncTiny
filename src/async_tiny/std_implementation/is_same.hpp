#pragma once

#include "async_tiny/std_implementation/integral_constant.hpp"


namespace async_tiny
{
namespace std_implementation
{
	// reference - https://en.cppreference.com/w/cpp/types/is_same
	template<class T, class U>
	struct is_same : std_implementation::false_type {};
	
	template<class T>
	struct is_same<T, T> : std_implementation::true_type {};
}
}