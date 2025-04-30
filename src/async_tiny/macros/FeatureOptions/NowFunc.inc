#include "async_tiny/macros/FeatureOptions/Defaults.hpp"


#ifdef MF_SPECIFIC_SLEEP_TIME_UNIT
	#if (MF_SPECIFIC_SLEEP_TIME_UNIT == NANO_SECOND)
		#define NOW_FUNC_ async_tiny::time::now<time::TimeUnit::NANO_SECOND>
	#elif (MF_SPECIFIC_SLEEP_TIME_UNIT == MICRO_SECOND)
		#define NOW_FUNC_ async_tiny::time::now<time::TimeUnit::MICRO_SECOND>
	#elif (MF_SPECIFIC_SLEEP_TIME_UNIT == MILLI_SECOND)
		#define NOW_FUNC_ async_tiny::time::now<time::TimeUnit::MILLI_SECOND>
	#elif (MF_SPECIFIC_SLEEP_TIME_UNIT == SECOND)
		#define NOW_FUNC_ async_tiny::time::now<time::TimeUnit::SECOND>
	#else
		#error Unknown value of MF_SPECIFIC_SLEEP_TIME_UNIT.
	#endif
#else
	#define NOW_FUNC_ async_tiny::EventLoop::_sleepTimers[async_tiny::EventLoop::_currentTaskID].now
#endif
