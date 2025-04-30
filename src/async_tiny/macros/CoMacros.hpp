#pragma once

#include "async_tiny/StdImplementation.hpp"
#include "async_tiny/macros/UtilityMacros.hpp"

// Declares a coroutine
#define CO_DECL(RetType, Name, ArgType, Vars) \
/* A complete Coroutine class */\
class Name : public async_tiny::awaitables::coroutines::BasicCoroutine<BLANK_TO_VOID(AS_IS(RetType)), BLANK_TO_VOID(AS_IS(ArgType))> \
{ \
	public: \
	using BaseType = async_tiny::awaitables::coroutines::BasicCoroutine<BLANK_TO_VOID(AS_IS(RetType)), BLANK_TO_VOID(AS_IS(ArgType))>; \
	using ReturnType = typename BaseType::ReturnType; \
	using ArgumentType = typename BaseType::ArgumentType; \
	using CoroutineBase = typename BaseType::CoroutineBase; \
	using BaseType::_await; \
	using BaseType::CoroutineBase::CoroutineUtility::stage_; \
	using BaseType::CoroutineBase::StateUtility::_state; \
	\
	DISABLE_IF_BLANK(AS_IS(Vars))(AS_IS(struct Variables { Vars } vars;)) /* Variables that sustain across coroutine suspensions */\
	\
	/* This method holds the body of the coroutine defined by user */\
	bool _await( \
		/* Disable if RetType is void/blank */\
		DISABLE_IF_BLANK(VOID_TO_BLANK(AS_IS(RetType)))(ReturnType&) \
		\
		/* Disable if either RetType or ArgType or both are void/blank */\
		DISABLE_IF_BLANK( \
			BLANK_AND(VOID_TO_BLANK(AS_IS(RetType)), VOID_TO_BLANK(AS_IS(ArgType))) \
		)(,) \
		\
		/* Disable if ArgType is void/blank */\
		DISABLE_IF_BLANK(VOID_TO_BLANK(AS_IS(ArgType)))(ArgumentType&) \
	) \
	/* Enable if both RetType & ArgType are void/blank */\
	ENABLE_IF_BLANK( \
		BLANK_OR(VOID_TO_BLANK(AS_IS(RetType)), VOID_TO_BLANK(AS_IS(ArgType)))\
	)( \
		/* Overrides Awaitable<void, void>::_await */\
		final \
	); \
	void reset(void) final /* Overrides CoroutineUtility::reset */ {\
		CoroutineBase::CoroutineUtility::reset(); \
		DISABLE_IF_BLANK(AS_IS(Vars))(AS_IS(vars = Variables{};)) \
	} \
};


// Defines a declared coroutine
#define CO_DEF_ONLY_(RetType, Name, ArgType) \
bool Name::_await( \
	/* Disable if RetType is void/blank */\
	DISABLE_IF_BLANK(VOID_TO_BLANK(AS_IS(RetType)))(ReturnType& retVar_) \
	\
	/* Disable if either RetType or ArgType or both are void/blank */\
	DISABLE_IF_BLANK( \
		BLANK_AND(VOID_TO_BLANK(AS_IS(RetType)), VOID_TO_BLANK(AS_IS(ArgType))) \
	)(,) \
	\
	/* Disable if ArgType is void/blank */\
	DISABLE_IF_BLANK(VOID_TO_BLANK(AS_IS(ArgType)))(ArgumentType& args) \
) /*{Body}*/


// Declares and defines a coroutine
#define CO_DECL_N_DEF_(RetType, Name, ArgType, Vars) \
CO_DECL(AS_IS(RetType), AS_IS(Name), AS_IS(ArgType), AS_IS(Vars)) \
inline CO_DEF_ONLY_(AS_IS(RetType), AS_IS(Name), AS_IS(ArgType)) /*{Body}*/


// (Declares and) defines a coroutine 
// If 4 arguments are passed it declares and defines a coroutine
// If 3 arguments are passed it defines a declared coroutine
#define CO_DEF(RetType, Name, ArgType, ...) CO_DEF_(, ##__VA_ARGS__, CO_DECL_N_DEF_, CO_DEF_ONLY_)(AS_IS(RetType), AS_IS(Name), AS_IS(ArgType), ##__VA_ARGS__)
#define CO_DEF_(x0, x1, CHOSEN_MACRO, ...) CHOSEN_MACRO


#include "async_tiny/macros/FeatureOptions/CoroutineStagingMethod.inc"

// Reduces boilerplate code to create jump mechanism
#define CO_BEGIN(lastStageNo) \
constexpr uint8_t __last_stage_no = lastStageNo;\
\
/* Defined in async_tiny/macros/FeatureOptions/CoroutineStagingMethod.inc */\
CO_BEGIN_SWITCH_STATEMENT_(stage_, lastStageNo)\
_state = async_tiny::StateType::NOT_SUSPENDED;


// Reduces boilerplate code to end jump mechanism
#define CO_END() \
stage_ = 255;\
\
/* Defined in async_tiny/macros/FeatureOptions/CoroutineStagingMethod.inc */\
DUFFS_DEVICE_END_ \
return true;


#include "async_tiny/macros/FeatureOptions/DisableIfConstexpr.inc"
#include "async_tiny/macros/FeatureOptions/DisableSuspensionOnFuture.inc"


// Reduces boilerplate code to support suspension mechanism
#define CO_AWAIT(stageNo, awaitable, ...) \
{\
	static_assert(stageNo<=__last_stage_no, "stageNo exceeded last_stage_no");\
	stage_ = stageNo;\
	\
	/* Defined in async_tiny/macros/FeatureOptions/DisableSuspensionOnFuture.inc */\
	PREVENT_AWAITING_ON_FUTURE_(awaitable);\
	\
	/* Defined in async_tiny/macros/FeatureOptions/DisableIfConstexpr.inc */\
	AT_IF_CONSTEXPR_ (\
		async_tiny::std_implementation::is_base_of<\
			async_tiny::awaitables::futures::AbstractFuture, \
			decltype(awaitable)\
		>::value\
	)\
	{\
		if (!awaitable._await(__VA_ARGS__)) return false;\
	}\
	\
	/* Defined in async_tiny/macros/FeatureOptions/CoroutineStagingMethod.inc */\
	MARK_STAGE_(stageNo);\
	\
	/* Defined in async_tiny/macros/FeatureOptions/DisableIfConstexpr.inc */\
	AT_IF_CONSTEXPR_ (\
		!async_tiny::std_implementation::is_base_of<\
			async_tiny::awaitables::futures::AbstractFuture, \
			decltype(awaitable)\
		>::value\
	)\
	{\
		if (!awaitable._await(__VA_ARGS__)) return false;\
	}\
}


// Reduces boilerplate code to suspend coroutine only for 1 EventLoop cycle
#define CO_NAP(stageNo) \
{\
	static_assert(stageNo<=__last_stage_no, "stageNo exceeded last_stage_no");\
	stage_ = stageNo;\
	return false;\
	MARK_STAGE_(stageNo);\
}


#include "async_tiny/macros/FeatureOptions/DisableCoSleep.inc"


// Reduces boilerplate code to suspend coroutine for specific time
#define CO_SLEEP(stageNo, sleepTime /* async_tiny::time::Time object */) \
{\
	static_assert(stageNo<=__last_stage_no, "stageNo exceeded last_stage_no");\
	\
	/* Defined in async_tiny/macros/FeatureOptions/DisableCoSleep.inc */\
	PREVENT_CO_SLEEP_() \
	\
	async_tiny::EventLoop::_sleepTimers[async_tiny::EventLoop::_currentTaskID].set_unit(sleepTime.get_unit());\
	async_tiny::EventLoop::_sleepTimers[async_tiny::EventLoop::_currentTaskID].set_value(sleepTime.now()+sleepTime.get_value());\
	stage_ = stageNo;\
	return false;\
	\
	/* Defined in async_tiny/macros/FeatureOptions/CoroutineStagingMethod.inc */\
	MARK_STAGE_(stageNo);\
}


// Reduces boilerplate code to suspend coroutine until condition is true
#define CO_UNTIL(stageNo, condition) \
{\
	static_assert(stageNo<=__last_stage_no, "stageNo exceeded last_stage_no");\
	stage_ = stageNo;\
	\
	/* Defined in async_tiny/macros/FeatureOptions/CoroutineStagingMethod.inc */\
	MARK_STAGE_(stageNo);\
	if (!(condition)) return false;\
}


// Reduces boilerplate code to return from coroutine
#define CO_RETURN(returnValue) \
{\
	DISABLE_IF_BLANK(AS_IS(returnValue))(retVar_ = returnValue);\
	stage_ = 255;\
	return true;\
}
