#include "PayOff3.h"
#include "PayOffConstructible.h"
#include "PayOffBridge.h"
#include "PayOffFactory.h"
#include <string>
#include <iostream>
#include <memory>

int main()
{
	double Strike;
	std::string name;

	std::cout << "Enter strike\n";
	std::cin >> Strike;

	std::cout << "\nPay-off name\n";
	std::cin >> name;

	std::shared_ptr<PayOff> PayOffPtr = PayOffFactory::Instance().CreatePayOff(name, Strike);

	if (PayOffPtr != NULL) {
		double Spot;
		
		std::cout << "\nspot\n";
		std::cin >> Spot;

		std::cout << "\n" << PayOffPtr->operator()(Spot) << "\n";
	}

	std::cin.ignore();
	std::cin.get();
	return 0;
}