#ifndef MEDIATORPATTERN_H
#define MEDIATORPATTERN_H

#include <iostream>
#include <string>
#include <memory>

namespace MediatorPattern
{
class BaseComponent;

class Mediator
{
public:
	virtual ~Mediator() = default;
	virtual void Notify(BaseComponent* sender, std::string event) const = 0;
};

class BaseComponent
{
public:
	virtual ~BaseComponent() = default;
	BaseComponent(Mediator* mediator = nullptr);
	void set_mediator(Mediator* mediator);
protected:
	Mediator* _mediator_;
};

class Component1 : public BaseComponent
{
public:
	using Ptr = std::unique_ptr<Component1>;
	void doA();
	void doB();
};

class Component2 : public BaseComponent
{
public:
	using Ptr = std::unique_ptr<Component2>;
	void doC();
	void doD();
};

class ConcreteMediator : public Mediator
{
public:
	using Ptr = std::unique_ptr<ConcreteMediator>;
	ConcreteMediator(Component1* c1, Component2* c2);
	void Notify(BaseComponent* sender, std::string event) const override;
private:
	Component1* _component1;
	Component2* _component2;
};

}

#endif
