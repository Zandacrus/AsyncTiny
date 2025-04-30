#define PREVENT_FEATURE_MODIFICATION

#include "EventLoop.decl.hpp"


namespace async_tiny
{
	uint8_t EventLoop::_taskLimit = 0;
	uint8_t EventLoop::_currentTaskID = 0;
	awaitables::tasks::TaskBase** EventLoop::_tasks = nullptr;
	utilities::CoroutineUtility** EventLoop::_coroutines = nullptr;
	awaitables::futures::AbstractFuture** EventLoop::_suspensionFutures = nullptr;
	time::Time* EventLoop::_sleepTimers = nullptr;
	uint8_t* EventLoop::_availableTaskStack = nullptr;
	uint8_t EventLoop::_availableTaskSlot = 0;
}
