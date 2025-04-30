#pragma once


namespace async_tiny
{
namespace std_implementation
{
	// reference - https://en.cppreference.com/w/cpp/types/remove_reference
	template<class T> struct remove_reference { typedef T type; };
	template<class T> struct remove_reference<T&> { typedef T type; };
	template<class T> struct remove_reference<T&&> { typedef T type; };
	
	template<class T> using remove_reference_t = typename remove_reference<T>::type;
}
}