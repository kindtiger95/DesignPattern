#include "TemplateMethodPattern.h"

using namespace TemplateMethodPattern;

void TemplateMethodPatternTest()
{
	std::cout << "Same client code can work with different subclasses : " << std::endl;
	ConcreteClass1::Ptr concreteClass1(new ConcreteClass1);
	concreteClass1->templateMethod();
	std::cout << std::endl;

	std::cout << "Same client code can work with different subclasses : " << std::endl;
	ConcreteClass2::Ptr concreteClass2(new ConcreteClass2);
	concreteClass2->templateMethod();

}
