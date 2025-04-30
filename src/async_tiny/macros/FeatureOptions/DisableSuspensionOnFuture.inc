#include "async_tiny/macros/FeatureOptions/Defaults.hpp"

#if (MF_DISABLE_SUSPENSION_ON_FUTURE == true)
	#define SUSPEND_ON_FUTURE_CONDITION_ false
	
	#define PREVENT_AWAITING_ON_FUTURE_(awaitable) \
	static_assert(\
		!async_tiny::std_implementation::is_base_of<\
			async_tiny::awaitables::futures::AbstractFuture, \
			decltype(awaitable)\
		>::value, \
		"Cannot await Future-like object when MF_DISABLE_SUSPENSION_ON_FUTURE is true"\
	);
#elif (MF_DISABLE_SUSPENSION_ON_FUTURE == false)
	#define SUSPEND_ON_FUTURE_CONDITION_ (\
		_suspensionFutures[_currentTaskID] != nullptr \
		&& \
		!_suspensionFutures[_currentTaskID]->_await()\
	)
	
	#define PREVENT_AWAITING_ON_FUTURE_(awaitable) 
#else
	#error MF_DISABLE_SUSPENSION_ON_FUTURE should either be true or false.
#endif
