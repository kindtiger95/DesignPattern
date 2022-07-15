#include "MediatorPattern.h"

using namespace MediatorPattern;

BaseComponent::BaseComponent(Mediator* mediator) : _mediator_(mediator)
{
}

void BaseComponent::set_mediator(Mediator* mediator)
{
	this->_mediator_ = mediator;
}

void Component1::doA()
{
	std::cout << "Component 1 dose A. " <<std::endl;
	this->_mediator_->Notify(this, "A");
}
void Component1::doB()
{
	std::cout << "Component 1 dose B. " <<std::endl;
	this->_mediator_->Notify(this, "B");
}
void Component2::doC()
{
	std::cout << "Component 2 dose C. " <<std::endl;
	this->_mediator_->Notify(this, "C");
}
void Component2::doD()
{
	std::cout << "Component 2 dose D. " <<std::endl;
	this->_mediator_->Notify(this, "D");
}
ConcreteMediator::ConcreteMediator(Component1* c1, Component2* c2) : _component1(c1), _component2(c2)
{
	this->_component1->set_mediator(this);
	this->_component2->set_mediator(this);
}
void ConcreteMediator::Notify(BaseComponent *sender, std::string event) const
{
	if (event == "A")
	{
		std::cout << "Mediator reacts on A and triggers following operations : " << std::endl;
		this->_component2->doC();
	}
	if (event == "D")
	{
		std::cout << "Mediator reacts on D and triggers following operations :" << std::endl;
		this->_component1->doB();
		this->_component2->doC();
	}
}
