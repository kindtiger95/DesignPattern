#ifndef DECORATORPATTERN_H
#define DECORATORPATTERN_H

#include <string>
#include <memory>

namespace DecoratorPattern
{
class Component
{
public:
	using Ptr = std::unique_ptr<Component>;

	virtual ~Component() = default;
	virtual std::string operation() const = 0;
};

class ConcreteComponent : public Component
{
public:
	std::string operation() const override;
};

class Decorator : public Component
{
public:
	Decorator(Component* component);
	std::string operation() const override;

protected:
	Component* _component;
};

class ConcreteDecoratorA : public Decorator
{
public:
	ConcreteDecoratorA(Component* component);
	std::string operation() const override;
};

class ConcreteDecoratorB : public Decorator
{
public:
	ConcreteDecoratorB(Component* component);
	std::string operation() const override;
};
}

#endif
