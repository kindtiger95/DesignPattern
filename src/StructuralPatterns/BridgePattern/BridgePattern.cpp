#include "BridgePattern.h"

using namespace BridgePattern;

std::string ConcreteImplementationA::operationImple() const
{
	return "ConcreteImplementationA: Here's the result on the platform A.\n";
}
std::string ConcreteImplementationB::operationImple() const
{
	return "ConcreteImplementationB: Here's the result on the platform B.\n";
}

Abstraction::Abstraction(Implementation* implementation) : _imple(implementation)
{

}

std::string Abstraction::operation() const
{
	return "Abstraction: Base operation with:\n" +
	           this->_imple->operationImple();
}

ExtendedAbstraction::ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation)
{

}

std::string ExtendedAbstraction::operation() const
{
	return "ExtendedAbstraction: Extended operation with:\n" +
	           this->_imple->operationImple();
}
