#include "StatePattern.h"
#include <memory>

void StatePatternTest()
{
	std::unique_ptr<Context> context(new Context(new ConcreteStateA()));
	context->request1();
	context->request2();
}
