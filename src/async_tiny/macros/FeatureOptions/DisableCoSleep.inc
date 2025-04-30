#include "async_tiny/macros/FeatureOptions/Defaults.hpp"
#include "async_tiny/macros/FeatureOptions/NowFunc.inc"


#if (MF_DISABLE_CO_SLEEP == true)
	#define SLEEP_CONDITION_ false
	
	#define PREVENT_CO_SLEEP_() \
	static_assert(\
		false, \
		"Cannot use CO_SLEEP macro when MF_DISABLE_CO_SLEEP is true"\
	);
#elif (MF_DISABLE_CO_SLEEP == false)
	#define SLEEP_CONDITION_ NOW_FUNC_() < _sleepTimers[_currentTaskID].get_value()
	
	#define PREVENT_CO_SLEEP_() 
#else
	#error MF_DISABLE_CO_SLEEP should either be true or false.
#endif
