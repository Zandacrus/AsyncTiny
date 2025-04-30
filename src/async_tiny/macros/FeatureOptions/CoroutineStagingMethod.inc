#include "async_tiny/macros/FeatureOptions/Defaults.hpp"


#if (MF_COROUTINE_STAGING_METHOD == IF_STATEMENT)
	// Used to create a stage within a coroutine. 
	// Used in CO_AWAIT, CO_NAP, CO_SLEEP, CO_UNTIL 
	#define MARK_STAGE_(stageNo) stage##stageNo##_:;
	
	// Used in CO_BEGIN_SWITCH_STATEMENT_ 
	#define GOTO_STAGE_(stageNo) goto stage##stageNo##_;
	
	// Used in CO_BEGIN 
	#define CO_BEGIN_SWITCH_STATEMENT_(stageVar, lastStageNo) \
	switch(stageVar) \
	{ \
		case 0: break; \
		REPEAT(lastStageNo, GEN_CASE, GOTO_STAGE_) \
		default: return true; \
	}
	
	// Used in CO_END to properly close switch 
	// statement in case of DUFFS_DEVICE 
	#define DUFFS_DEVICE_END_ 
#elif (MF_COROUTINE_STAGING_METHOD == GOTO_STATEMENT)
	// Used to create a stage within a coroutine. 
	// Used in CO_AWAIT, CO_NAP, CO_SLEEP, CO_UNTIL 
	#define MARK_STAGE_(stageNo) stage##stageNo##_:;
	
	// Used in CO_BEGIN_SWITCH_STATEMENT_ 
	#define GOTO_STAGE_(stageNo) goto stage##stageNo##_;
	
	// Used in CO_BEGIN 
	#define CO_BEGIN_SWITCH_STATEMENT_(stageVar, lastStageNo) \
	switch(stageVar) \
	{ \
		case 0: break; \
		REPEAT(lastStageNo, GEN_CASE, GOTO_STAGE_) \
		default: return true; \
	}
	
	// Used in CO_END to properly close switch 
	// statement in case of DUFFS_DEVICE 
	#define DUFFS_DEVICE_END_ 
#elif (MF_COROUTINE_STAGING_METHOD == DUFFS_DEVICE)
	#define MARK_STAGE_(stageNo) case stageNo:;
	
	#define CO_BEGIN_SWITCH_STATEMENT_(stageVar, lastStageNo) \
	switch(stageVar) \
	{ \
		case 0:
	
	#define DUFFS_DEVICE_END_ \
	default:; \
	}
#else
	#error Unknown value of MF_COROUTINE_STAGING_METHOD.
#endif
