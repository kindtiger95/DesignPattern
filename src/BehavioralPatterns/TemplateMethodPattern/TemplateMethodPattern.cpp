#include "TemplateMethodPattern.h"

using namespace TemplateMethodPattern;

void AbstractClass::templateMethod() const
{
	this->baseOperation1();
	this->requireOperations1();
	this->baseOperation2();
	this->Hook1();

	this->requireOperations2();
	this->baseOperation3();
	this->Hook2();
}

void AbstractClass::baseOperation1() const
{
	std::cout << "AbstractClass says : I am doing the bulk of the work" << std::endl;
}
void AbstractClass::baseOperation2() const
{
	std::cout << "AbstractClass says : But I let subclasses override some operations." << std::endl;
}
void AbstractClass::baseOperation3() const
{
	std::cout << "AbstractClass says : But I am doing the bulk of the work anyway. " << std::endl;
}
void ConcreteClass1::requireOperations1() const
{
	std::cout << "ConcreteClass1 says : Implemented Operation1 " << std::endl;
}
void ConcreteClass1::requireOperations2() const
{
	std::cout << "ConcreteClass1 says : Implemented Operation2 " << std::endl;
}
void ConcreteClass2::requireOperations1() const
{
	std::cout << "ConcreteClass2 says : Implemented Operation1 " << std::endl;
}
void ConcreteClass2::requireOperations2() const
{
	std::cout << "ConcreteClass2 says : Implemented Operation2 " << std::endl;
}
void ConcreteClass2::Hook1() const
{
	std::cout << "ConcreteClass2 says : Overriden Hook1 " << std::endl;
}
