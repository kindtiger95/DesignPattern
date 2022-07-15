#include "MediatorPattern.h"

using namespace MediatorPattern;

void MediatorPatternTest()
{
	Component1::Ptr component1(new Component1);
	Component2::Ptr component2(new Component2);
	ConcreteMediator::Ptr mediator(new ConcreteMediator(component1.get(), component2.get()));

	std::cout << "Client triggers operation A. " << std::endl;
	component1->doA();
	std::cout << std::endl;

	std::cout << "Client triggers operation D. " << std::endl;
	component2->doD();
}
