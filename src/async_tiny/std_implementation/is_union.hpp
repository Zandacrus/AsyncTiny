#pragma once

#include "async_tiny/std_implementation/integral_constant.hpp"


namespace async_tiny
{
namespace std_implementation
{
	// reference - https://github.com/gcc-mirror/gcc/blob/4d9da4199d1cc067a43c29a40d4f4b17ac10319c/libstdc%2B%2B-v3/include/tr1/type_traits#L210C15-L211C1
	template<typename T>
    struct is_union : public integral_constant<bool, __is_union(T)> {};
}
}