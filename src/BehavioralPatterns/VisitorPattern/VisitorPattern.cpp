#include "VisitorPattern.h"

using namespace VisitorPattern;

void ConcreteComponentA::Accept(Visitor *visitor) const
{
	visitor->VisitConcreteComponentA(this);
}
std::string ConcreteComponentA::ExclusiveMethodOfConcreteComponentA() const
{
	return "A";
}
void ConcreteComponentB::Accept(Visitor *visitor) const
{
	visitor->VisitConcreteComponentB(this);
}
std::string ConcreteComponentB::SpecialMethodOfConcreteComponentB() const
{
	return "B";
}
void ConcreteVisitor1::VisitConcreteComponentA(const ConcreteComponentA *element) const
{
	std::cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor1" << std::endl;
}

void ConcreteVisitor1::VisitConcreteComponentB(const ConcreteComponentB *element) const
{
	std::cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor1" << std::endl;
}
void ConcreteVisitor2::VisitConcreteComponentA(const ConcreteComponentA *element) const
{
	std::cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor2" << std::endl;
}
void ConcreteVisitor2::VisitConcreteComponentB(const ConcreteComponentB *element) const
{
	std::cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor2" << std::endl;
}
