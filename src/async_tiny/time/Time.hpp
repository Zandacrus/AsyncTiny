#pragma once

#include "async_tiny/time/Time.decl.hpp"


namespace async_tiny
{
namespace time
{
	inline TimeUnit Time::get_unit(void)
	{
		return m_unit;
	}
	
	inline void Time::set_unit(TimeUnit p_unit)
	{
		m_unit = p_unit;
	}
	
	#include "async_tiny/macros/FeatureOptions/DisableIfConstexpr.inc"
	
	inline uint32_t Time::get_value(void)
	{
		// Defined in async_tiny/macros/FeatureOptions/DisableIfConstexpr.inc
		AT_IF_CONSTEXPR_ (alignof(uint8_t) == 1)
		{
			return *static_cast<uint32_t*>(static_cast<void*>(m_value));
		}
		else
		{
			return (m_value[3]<<24) | (m_value[2]<<16)
				| (m_value[1]<<8) | m_value[0];
		}
	}
	
	inline void Time::set_value(uint32_t p_value)
	{
		// Defined in async_tiny/macros/FeatureOptions/DisableIfConstexpr.inc
		AT_IF_CONSTEXPR_ (alignof(uint8_t) == 1)
		{
			*static_cast<uint32_t*>(static_cast<void*>(m_value)) = p_value;
		}
		else
		{
			m_value[3] = p_value>>24;
			m_value[2] = p_value>>16;
			m_value[1] = p_value>>8;
			m_value[0] = p_value;
		}
	}
	
	inline void Time::reset(void)
	{
		// Defined in async_tiny/macros/FeatureOptions/DisableIfConstexpr.inc
		AT_IF_CONSTEXPR_ (alignof(uint8_t) == 1)
		{
			*static_cast<uint32_t*>(static_cast<void*>(m_value)) = 0;
		}
		else
		{
			m_value[3] = 0;
			m_value[2] = 0;
			m_value[1] = 0;
			m_value[0] = 0;
		}
	}
	
	inline Time nsec(uint32_t val) { return Time(val, TimeUnit::NANO_SECOND); }
	inline Time usec(uint32_t val) { return Time(val, TimeUnit::MICRO_SECOND); }
	inline Time msec(uint32_t val) { return Time(val, TimeUnit::MILLI_SECOND); }
	inline Time sec(uint32_t val) { return Time(val, TimeUnit::SECOND); }
}
}
