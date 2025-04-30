#pragma once


namespace async_tiny
{
namespace std_implementation
{
	// reference - https://en.cppreference.com/w/cpp/types/integral_constant
	template<class T, T v>
	struct integral_constant
	{
		static constexpr T value = v;
		using value_type = T;
		using type = integral_constant; // using injected-class-name
		constexpr operator value_type() const noexcept { return value; }
		constexpr value_type operator()() const noexcept { return value; } // since c++14
	};
	
	template< bool B >
	using bool_constant = integral_constant<bool, B>;
	
	typedef bool_constant<true> true_type;
	typedef bool_constant<false> false_type;
}
}