#pragma once

#include "async_tiny/std_implementation/integral_constant.hpp"
#include "async_tiny/std_implementation/is_class.hpp"


namespace async_tiny
{
namespace std_implementation
{
	// reference - https://en.cppreference.com/w/cpp/types/is_base_of
	namespace internal
	{
		template<typename B>
		std_implementation::true_type test_ptr_conv(const volatile B*);
		template<typename>
		std_implementation::false_type test_ptr_conv(const volatile void*);
	
		template<typename B, typename D>
		auto test_is_base_of(int) -> decltype(test_ptr_conv<B>(static_cast<D*>(nullptr)));
		template<typename, typename>
		auto test_is_base_of(...) -> std_implementation::true_type; // private or ambiguous base
	}
	
	template<typename Base, typename Derived>
	struct is_base_of :
		std_implementation::integral_constant<
			bool,
			std_implementation::is_class<Base>::value &&
			std_implementation::is_class<Derived>::value &&
			decltype(internal::test_is_base_of<Base, Derived>(0))::value
		> {};
}
}