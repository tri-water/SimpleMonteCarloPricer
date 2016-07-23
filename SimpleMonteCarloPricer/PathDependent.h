#pragma once
#include <vector>
#include <memory>
/* 
	we define the CashFlow and the PathDependent classes
	which give our path-dependent exotic option
*/

class CashFlow
{
	/* this is a container for storing time index
	   and the corresponding value at the time
	*/
public:
	double Amount;
	unsigned long TimeIndex;

	CashFlow(unsigned long fTimeIndex = 0UL, double fAmout = 0.0) :
		TimeIndex(fTimeIndex), Amount(fAmout) {}; // default values are required for stl containers.
};

class PathDependent
{
	/* base class defines the interface
	   and some commonly shared members
	*/
public:
	PathDependent(const std::vector<double>& LookAtTimes);
	const std::vector<double>& GetLookAtTimes() const;

	virtual unsigned long MaxNumberOfCashFlows() const = 0;
	virtual std::vector<double> PossibleCashFlowTimes() const = 0;
	virtual unsigned long CashFlows(const std::vector<double>& SpotValues, std::vector<CashFlow>& GeneratedFlows) const = 0;
	virtual std::shared_ptr<PathDependent> clone() const = 0;
	virtual ~PathDependent() {};

private:
	std::vector<double> LookAtTimes;
};
