#pragma once

#include "async_tiny/std_implementation/remove_cv.hpp"
#include "async_tiny/std_implementation/remove_reference.hpp"


namespace async_tiny
{
namespace std_implementation
{
	// reference - https://en.cppreference.com/w/cpp/types/remove_cvref
	template<class T>
	struct remove_cvref
	{
		typedef std_implementation::remove_cv_t<std_implementation::remove_reference_t<T>> type;
	};
	
	template<class T> using remove_cvref_t = typename remove_cvref<T>::type;
}
}