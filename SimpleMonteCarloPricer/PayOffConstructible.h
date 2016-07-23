#pragma once
#include <iostream>
#include "PayOff3.h"
#include "PayOffFactory.h"
#include <string>
#include <memory>

template <class T>
class PayOffHelper
{
public:
	PayOffHelper(std::string);
	static std::shared_ptr<PayOff> Create(double);
};

template <class T>
std::shared_ptr<PayOff> PayOffHelper<T>::Create(double Strike)
{
	return std::shared_ptr<PayOff>(new T(Strike));
}

template <class T>
PayOffHelper<T>::PayOffHelper(std::string id)
{
	PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
	// Pass the function pointer of the static Create function to PayOffFactory
	thePayOffFactory.RegisterPayOff(id, PayOffHelper<T>::Create);
}