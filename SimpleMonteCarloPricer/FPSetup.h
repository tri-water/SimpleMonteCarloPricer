#pragma once
#include <Windows.h>
#include <stdexcept>

class float_exception : public std::exception {};
class fe_denormal_operand : public float_exception {};
class fe_divide_by_zero : public float_exception {};
class fe_inexact_result : public float_exception {};
class fe_invalid_operation : public float_exception {};
class fe_overflow : public float_exception {};
class fe_stack_check : public float_exception {};
class fe_underflow : public float_exception {};

void se_fe_trans_func(unsigned int u, EXCEPTION_POINTERS* pExp);

void EnableFloatingPointExceptions();