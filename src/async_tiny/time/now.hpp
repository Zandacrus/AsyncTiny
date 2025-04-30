#pragma once

#include "TimeUnit.hpp"

extern "C"
{
#include <stdint.h>
}


namespace async_tiny
{
namespace time
{
	template <TimeUnit TU> uint32_t now(void);
}
}
