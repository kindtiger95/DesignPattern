#include "FacadePattern.h"

using namespace FacadePattern;

std::string Subsystem1::operation1() const
{
	return "Subsystem1: Ready! \n";
}
std::string Subsystem1::operationN() const
{
	return "Subsystem1: Go! \n";
}
std::string Subsystem2::operation1() const
{
	return "Subsystem2: Get Ready! \n";
}
std::string Subsystem2::operationZ() const
{
	return "Subsystem2: Fire! \n";
}
Facade::Facade(Subsystem1* subsystem1, Subsystem2* subsystem2)
{
#if __LINUX__
	this->_subsystem1 == subsystem1 ? : new Subsystem1;
	this->_subsystem2 == subsystem2 ? : new Subsystem2;
#elif _WIN32
	if (this->_subsystem1 != subsystem1)
		this->_subsystem1 = new Subsystem1;
	if (this->_subsystem2 != subsystem2)
		this->_subsystem2 = new Subsystem2;
#endif
}
std::string Facade::operation()
{
	std::string res = "Facade initializes subsystems:\n";
	res += this->_subsystem1->operation1();
	res += this->_subsystem2->operation1();
	res += "Facade orders subsystems to perform the action:\n";
	res += this->_subsystem1->operationN();
	res += this->_subsystem2->operationZ();
	return res;
}
