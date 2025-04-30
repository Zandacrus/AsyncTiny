#include "async_tiny/macros/FeatureOptions/Defaults.hpp"


#if (MF_WAIT_FOR_ALL_TASKS == true)
	#define EXECUTE_TASK0_() 
	
	#define CURRENT_TASK_ID_INITIAL_VALUE_ 0
#elif (MF_WAIT_FOR_ALL_TASKS == false)
	#define EXECUTE_TASK0_() \
	_currentTaskID=0; \
	if (_tasks[0]!=nullptr && _execute_current_task()) \
	{ \
		_remove_current_task(); \
		_remove_all_tasks(); \
		return true; \
	}
	
	#define CURRENT_TASK_ID_INITIAL_VALUE_ 1
#else
	#error MF_WAIT_FOR_ALL_TASKS should either be true or false.
#endif
