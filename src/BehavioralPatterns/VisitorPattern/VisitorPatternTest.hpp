#include "VisitorPattern.h"

#include <array>

using namespace VisitorPattern;

void VisitorPatternTest()
{
	std::array<const VisitorPattern::Component*, 2> components = {new ConcreteComponentA, new ConcreteComponentB};
	std::cout << "The client code works with all visitors via the base Visitor interface : " << std::endl;
	ConcreteVisitor1* visitor1 = new ConcreteVisitor1;

	for (auto& it : components)
		it->Accept(visitor1);

	std::cout << std::endl;
	std::cout << "It allows the same client code to work with different types of visitors:\n";
	ConcreteVisitor2* visitor2 = new ConcreteVisitor2;

	for (auto& it : components)
		it->Accept(visitor2);


	for (auto& it : components)
	{
		delete it;
	}
	delete visitor1;
	delete visitor2;
}
