#include "async_tiny/macros/FeatureOptions/Defaults.hpp"


#if (MF_DISABLE_IF_CONSTEXPR == true)
	#define AT_IF_CONSTEXPR_ if
#elif (MF_DISABLE_IF_CONSTEXPR == false)
	#define AT_IF_CONSTEXPR_ if constexpr
#else
	#error MF_DISABLE_IF_CONSTEXPR should either be true or false.
#endif
