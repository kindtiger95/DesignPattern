#include "FacadePattern.h"

using namespace FacadePattern;

void FacadePatternTest()
{
	FacadePattern::Subsystem1::Ptr subsystem1(new Subsystem1());
	FacadePattern::Subsystem2::Ptr subsystem2(new Subsystem2());

	FacadePattern::Facade::Ptr facade(new Facade(subsystem1.get(), subsystem2.get()));
	std::cout << facade->operation() << std::endl;
}
