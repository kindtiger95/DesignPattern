#include "StrategyPattern.h"

using namespace StrategyPattern;

void StrategyPatternTest()
{
	ConcreteStrategyA::Ptr strategyA(new ConcreteStrategyA);
	ConcreteStrategyB::Ptr strategyB(new ConcreteStrategyB);
	StrategyPattern::Context::Ptr context(new StrategyPattern::Context(strategyA.get()));

	std::cout << "Client : Strategy is set to normal sorting. " << std::endl;

	context->doSomeBusinessLogic();
	std::cout << std::endl;
	std::cout << "Client : Strategy is set to reverse sorting. " << std::endl;
	context->set_strategy(strategyB.get());
	context->doSomeBusinessLogic();
}
