#include "FactoryMethodPattern.h"

void FactoryMethodPatternTest()
{
	std::cout << "APP : Launched with the ConcreteCreator1. " << std::endl;
	std::unique_ptr<FactoryMethod::Creator> creator1(new FactoryMethod::ConcreteCreator1());
	creator1->someOperation();
	std::cout << std::endl;

	std::cout << "APP : Launched with the ConcreteCreator2. " << std::endl;
	std::unique_ptr<FactoryMethod::Creator> creator2(new FactoryMethod::ConcreteCreator2());
	creator2->someOperation();
}
