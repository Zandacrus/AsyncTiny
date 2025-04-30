#pragma once

extern "C"
{
#include <stdint.h>
}


namespace async_tiny
{
namespace time
{
	enum class TimeUnit : uint8_t
	{
		NANO_SECOND,
		MICRO_SECOND,
		MILLI_SECOND,
		SECOND
	};
}
}
