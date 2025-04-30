#define PREVENT_FEATURE_MODIFICATION

#include "async_tiny/time/now.hpp"
#include "async_tiny/time/Time.decl.hpp"


namespace async_tiny
{
namespace time
{
	uint32_t Time::now(void)
	{
		switch (m_unit)
		{
			case TimeUnit::NANO_SECOND:
				return time::now<TimeUnit::NANO_SECOND>();
			
			case TimeUnit::MICRO_SECOND:
				return time::now<TimeUnit::MICRO_SECOND>();
			
			case TimeUnit::MILLI_SECOND:
				return time::now<TimeUnit::MILLI_SECOND>();
			
			default:
				return time::now<TimeUnit::SECOND>();
		}
	}
}
}
