#pragma once

#include "async_tiny/macros/RepeatMacro.hpp"


#define AS_IS(...) __VA_ARGS__
#define AS_IS_(...) __VA_ARGS__

#define MAKE_BLANK(...) 

#define EXPAND(x) x
#define FIRST_TOKEN(x, ...) x

#define PREPEND_COMMA_IF_NOT_BLANK(...) , ##__VA_ARGS__

// Returns IF_MACRO if X is blank (desired behaviour) 
// or X has leading comma(s)      (limitation)
// otherwise returns ELSE_MACRO
#define IF_BLANK_CHOOSE_MACRO(X, IF_MACRO, ELSE_MACRO) IF_BLANK_CHOOSE_MACRO_(FIRST_TOKEN(X,), IF_MACRO, ELSE_MACRO)
#define IF_BLANK_CHOOSE_MACRO_(X, IF_MACRO, ELSE_MACRO) IF_BLANK_CHOOSE_MACRO__(PREPEND_COMMA_IF_NOT_BLANK(X), IF_MACRO, ELSE_MACRO)
#define IF_BLANK_CHOOSE_MACRO__(X, IF_MACRO, ELSE_MACRO) AS_IS_(IF_BLANK_CHOOSE_MACRO___(X, ELSE_MACRO, IF_MACRO))
#define IF_BLANK_CHOOSE_MACRO___(x0, x1, CHOSEN_MACRO, ...) CHOSEN_MACRO

// Usage - ENABLE_IF_BLANK(X)(Y)
// Returns Y if X is blank otherwise returns blank
// Limitation of IF_BLANK_CHOOSE_MACRO applies
#define ENABLE_IF_BLANK(X) IF_BLANK_CHOOSE_MACRO(AS_IS(X), AS_IS, MAKE_BLANK)

// Usage - DISABLE_IF_BLANK(X)(Y)
// Returns blank if X is blank otherwise returns Y
// Limitation of IF_BLANK_CHOOSE_MACRO applies
#define DISABLE_IF_BLANK(X) IF_BLANK_CHOOSE_MACRO(AS_IS(X), MAKE_BLANK, AS_IS)

// Returns 1 if neither X nor Y is blank otherwise returns blank
// Limitation of IF_BLANK_CHOOSE_MACRO applies
#define BLANK_AND(X, Y) \
IF_BLANK_CHOOSE_MACRO( \
	IF_BLANK_CHOOSE_MACRO(AS_IS(X), MAKE_BLANK, AS_IS)(Y) \
, MAKE_BLANK, AS_IS)(1)

// Returns blank if both X and Y is blank otherwise returns 1
// Limitation of IF_BLANK_CHOOSE_MACRO applies
#define BLANK_OR(X, Y) IF_BLANK_CHOOSE_MACRO(AS_IS(X) AS_IS(Y), MAKE_BLANK, AS_IS)(1)

// Returns void if X is blank otherwise returns X
// Limitation of IF_BLANK_CHOOSE_MACRO applies
#define BLANK_TO_VOID(X) IF_BLANK_CHOOSE_MACRO(AS_IS(X), void MAKE_BLANK, AS_IS)(X)

// Returns blank if X is void or X is void,... 
// otherwise returns X
#define VOID_TO_BLANK(X) VOID_TO_BLANK_(FIRST_TOKEN(X,))(X)
#define VOID_TO_BLANK_(X) VOID_TO_BLANK__(X)
#define VOID_TO_BLANK__(X) IF_BLANK_CHOOSE_MACRO(BLANK_##X, MAKE_BLANK, AS_IS)
#define BLANK_void

// Generates a case for a switch statement based on CASE_MACRO
#define GEN_CASE(case_no, CASE_MACRO, ...) \
case case_no: CASE_MACRO(case_no, ##__VA_ARGS__)
