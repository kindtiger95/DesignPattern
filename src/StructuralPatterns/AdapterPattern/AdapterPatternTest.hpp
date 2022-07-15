#include "AdapterPattern.h"
#include <memory>

using namespace AdapterPattern;

void AdapterPatternTest()
{
	std::cout << "Client: I can work just fine with the Target objects : " << std::endl;;
	std::unique_ptr<Target> target(new Target());
	std::cout << target->request() << std::endl;

	std::unique_ptr<Adaptee> adaptee(new Adaptee());
	std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand next line " << std::endl;
	std::cout << "Adaptee: " << adaptee->specificRequest() << std::endl;

	std::cout << "Client: But I can work with it via the Adapter : " << std::endl;
	std::unique_ptr<Adapter> new_adapter(new Adapter(adaptee.get()));
	std::cout << new_adapter->request() << std::endl;
}
