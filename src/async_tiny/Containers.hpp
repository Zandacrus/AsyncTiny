#pragma once


// Makes a templated container with custom variable name
// Used in Task and Future classes
#define CONTAINER(containerName, valueName) \
template <typename ValueType> struct containerName##Container {ValueType valueName;}; \
template <> struct containerName##Container<void> {};

namespace async_tiny
{
	// defines ResultContainer class template [used in Future and Task classes]
	CONTAINER(Result, _result);
	
	// defines ArgContainer class template [used in Task class]
	CONTAINER(Arg, _args);
}

#undef CONTAINER