#include "FPSetup.h"
#include <float.h>
#include <iostream>
// Structured Exception handling (SEH) C-style exception, unsigned int, provide by windows (_try/_except) 
// C++ Exception handling (EH), has type, impleted by compiler (try / catch)

void se_fe_trans_func(unsigned int u, EXCEPTION_POINTERS* pExp)
{
	std::cout << u;
	switch (u)
	{
	case STATUS_FLOAT_DENORMAL_OPERAND:
		throw fe_denormal_operand();
	case STATUS_FLOAT_DIVIDE_BY_ZERO:
		throw fe_divide_by_zero();
	case STATUS_FLOAT_INEXACT_RESULT:
		throw fe_inexact_result();
	case STATUS_FLOAT_INVALID_OPERATION:
		throw fe_invalid_operation();
	case STATUS_FLOAT_OVERFLOW:
		throw fe_overflow();
	case STATUS_FLOAT_UNDERFLOW:
		throw fe_underflow();
	case STATUS_FLOAT_STACK_CHECK:
		throw fe_stack_check();
	};
	throw float_exception();
}

void EnableFloatingPointExceptions()
{
	unsigned int control_word;
	// defined in Windows.h.
	//This tells the compiler how to translate structured exception into C++ exception
	_set_se_translator(se_fe_trans_func);

	// Enabling floating point exceptions
	_controlfp_s(&control_word, _EM_INEXACT, _MCW_EM);
}