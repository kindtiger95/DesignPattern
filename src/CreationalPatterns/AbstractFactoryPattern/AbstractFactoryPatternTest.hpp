#include "AbstractFactoryPattern.h"
#include <iostream>

void AbstractFactoryPatternTest()
{
	auto A = Abstract::createPtr(Abstract::Type::A);
	auto B = Abstract::createPtr(Abstract::Type::B);

	std::cout << A->function() << std::endl;
	std::cout << B->function() << std::endl;
}
