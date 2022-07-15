#include "AbstractFactoryPattern.h"

Abstract::Ptr Abstract::createPtr(const Type& type)
{
	if (type == Abstract::Type::A)
		return Ptr(new ConcreteA());
	else if (type == Abstract::Type::B)
		return Ptr(new ConcreteB());

	return nullptr;
}

std::string ConcreteA::function() const
{
	 return "The result of the concreteA.";
}

std::string ConcreteB::function() const
{
	return "The result of the concreteB.";
}
