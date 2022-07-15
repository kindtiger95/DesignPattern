#include "DecoratorPattern.h"

using namespace DecoratorPattern;

std::string ConcreteComponent::operation() const
{
	return "ConcreteComponent";
}

Decorator::Decorator(Component* component) : _component(component) {}

std::string Decorator::operation() const
{
	return this->_component->operation();
}
ConcreteDecoratorA::ConcreteDecoratorA(Component* component) : Decorator(component) {}

std::string ConcreteDecoratorA::operation() const
{
	return "ConcreteDecoratorA(" + Decorator::operation() + ")";
}

ConcreteDecoratorB::ConcreteDecoratorB(Component* component) : Decorator(component) {}

std::string ConcreteDecoratorB::operation() const
{
	return "ConcreteDecoratorB(" + Decorator::operation() + ")";
}
