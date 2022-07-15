#include "PrototypePattern.h"
#include <memory>

void PrototypePatternTest()
{
	PrototypeFactory FrameFactory;

	std::cout << "Create Type 1" << std::endl;
	std::unique_ptr<PrototypeFrame> frame(FrameFactory.createPrototype(PrototypeFactory::Type::PROTOTYPE_1));
	frame->method(90);

	std::cout << std::endl;

	std::cout << "Create Type 2" << std::endl;
	frame.reset(FrameFactory.createPrototype(PrototypeFactory::Type::PROTOTYPE_2));
	frame->method(10);
}
