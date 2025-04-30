#pragma once

#include "async_tiny/time/Time.fwd.hpp"
#include "async_tiny/time/TimeUnit.hpp"

extern "C"
{
#include <stdint.h>
}


namespace async_tiny
{
namespace time
{
	class Time
	{
		public:
		
		Time(uint32_t p_value = 0, TimeUnit p_unit = TimeUnit::NANO_SECOND) : m_unit(p_unit) { set_value(p_value); }
		
		TimeUnit get_unit(void);
		
		void set_unit(TimeUnit);
		
		uint32_t get_value(void);
		
		void set_value(uint32_t);
		
		uint32_t now(void);
		
		void reset(void);
		
		protected:
		
		TimeUnit m_unit;
		
		// Used uint8_t[4] instead of uint32_t 
		// to save space due to alignment. 
		uint8_t m_value[4];
	};
}
}
