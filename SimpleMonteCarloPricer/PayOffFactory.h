#pragma once
#include "PayOff3.h"
#include <map>
#include <string>
#include <memory>
#include <boost\core\noncopyable.hpp>

template<class T>
class Singleton : private boost::noncopyable
{
public:
	static T& Instance() {
		static T one;
		return one;
	}
protected:
	Singleton() {};
};

// Singleton pattern: define a class that can only construct a single implementation
class PayOffFactory : public Singleton<PayOffFactory>
{
public:
	// the typedef allows us to refer to pointers to functions
	// which take in a double and spit out a PayOff* as CreatePayOffFunction
	typedef std::shared_ptr<PayOff> (*CreatePayOffFunction)(double);

	// a static function returns a static object, which will only be constructed once
	void RegisterPayOff(std::string, CreatePayOffFunction);
	std::shared_ptr<PayOff> CreatePayOff(std::string PayOffID, double Strike);
	~PayOffFactory() {};

private:
	std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
	PayOffFactory() {}
	// Keep the constructor and assignment function private
	// only allowing it called by static function Instance
	friend class Singleton<PayOffFactory>;

};