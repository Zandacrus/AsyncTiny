#pragma once


namespace async_tiny
{
namespace std_implementation
{
	// reference - https://en.cppreference.com/w/cpp/types/remove_cv
	template<class T> struct remove_cv { typedef T type; };
	template<class T> struct remove_cv<const T> { typedef T type; };
	template<class T> struct remove_cv<volatile T> { typedef T type; };
	template<class T> struct remove_cv<const volatile T> { typedef T type; };
	
	template<class T> using remove_cv_t = typename remove_cv<T>::type;
}
}