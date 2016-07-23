#pragma once
#include "PayOff3.h"
#include <memory>

class PayOffBridge
{
public:
	PayOffBridge(const PayOffBridge& original);
	PayOffBridge(const PayOff& innerPayOff);
	
	inline double operator()(double Spot) const;
	~PayOffBridge();
	PayOffBridge& operator=(const PayOffBridge& original);

private:
	std::shared_ptr<PayOff> ThePayOffPtr;
};

inline double PayOffBridge::operator()(double Spot) const
{
	return ThePayOffPtr->operator()(Spot);
}