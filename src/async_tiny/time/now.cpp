#define PREVENT_FEATURE_MODIFICATION

#include "now.hpp"

#if __has_include("chrono")
	#include <chrono>
	
	auto start = std::chrono::system_clock::now();
	#define NOW_NS_ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now() - start).count()
	#define NOW_US_ std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start).count()
	#define NOW_MS_ std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count()
	#define NOW_S_ std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start).count()
#elif defined ARDUINO
	#include <Arduino.h>
	
	#define NOW_NS_ micros()*1000
	#define NOW_US_ micros()
	#define NOW_MS_ millis()
	#define NOW_S_ millis()/1000
#else
	#error "No alternative for chrono"
#endif

namespace async_tiny
{
namespace time
{
	template <> uint32_t now<TimeUnit::NANO_SECOND>(void)
	{
		return NOW_NS_;
	}
	
	template <> uint32_t now<TimeUnit::MICRO_SECOND>(void)
	{
		return NOW_US_;
	}
	
	template <> uint32_t now<TimeUnit::MILLI_SECOND>(void)
	{
		return NOW_MS_;
	}
	
	template <> uint32_t now<TimeUnit::SECOND>(void)
	{
		return NOW_S_;
	}
}
}
