#include "DecoratorPattern.h"

using namespace DecoratorPattern;

void DecoratorPatternTest()
{
	DecoratorPattern::Component::Ptr simple(new ConcreteComponent());
	std::cout << "Clinet : I've got a simple component. " << std::endl;

	std::cout << "Result : " << simple->operation();
	std::cout << std::endl;

	DecoratorPattern::Component::Ptr decorator1(new ConcreteDecoratorA(simple.get()));
	DecoratorPattern::Component::Ptr decorator2(new ConcreteDecoratorB(decorator1.get()));

	std::cout << "Clinet: Now I've got a decorated component." << std::endl;
	std::cout << "Result : " << decorator2->operation();
	std::cout << std::endl;

}
