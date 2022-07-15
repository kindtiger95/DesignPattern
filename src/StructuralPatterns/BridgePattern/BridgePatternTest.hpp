#include "BridgePattern.h"

using namespace BridgePattern;

void BridgePatternTest()
{
	std::unique_ptr<Implementation> implementation(new ConcreteImplementationA());
	std::unique_ptr<Abstraction> abstraction(new Abstraction(implementation.get()));

	std::cout << abstraction->operation();

	std::cout << std::endl;

	implementation.reset(new ConcreteImplementationB());
	abstraction.reset(new ExtendedAbstraction(implementation.get()));

	std::cout << abstraction->operation();
}
