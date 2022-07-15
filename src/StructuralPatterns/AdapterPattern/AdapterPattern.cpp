#include "AdapterPattern.h"

using namespace AdapterPattern;

std::string Target::request() const
{
	return "Target: The default target's behavior.";
}
std::string Adaptee::specificRequest() const
{
	return ".eetpadA eht fo roivaheb laicepS";
}
Adapter::Adapter(Adaptee* adaptee) : _adaptee(adaptee)
{
}
std::string Adapter::request() const
{
	std::string to_reverse = this->_adaptee->specificRequest();
	std::reverse(to_reverse.begin(), to_reverse.end());
	return "Adapter: (TRANSLATED) " + to_reverse;
}
