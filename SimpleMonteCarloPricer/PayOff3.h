#pragma once
#include <memory>

class PayOff
{
public:
	PayOff() {};

	virtual ~PayOff() {}
	virtual double operator()(double Spot) const = 0;
	virtual std::shared_ptr<PayOff> clone() const = 0;

private:
	double Strike;
};

class PayOffCall : public PayOff
{
public:
	PayOffCall(double fStrike);

	virtual ~PayOffCall() {};
	virtual double operator() (double Spot) const;
	virtual std::shared_ptr<PayOff> clone() const;

private:
	double Strike;
};

class PayOffPut : public PayOff
{
public:
	PayOffPut(double fStrike);

	virtual ~PayOffPut() {};
	virtual double operator() (double Spot) const;
	virtual std::shared_ptr<PayOff> clone() const;
	

private:
	double Strike;	
};