#include "StatePattern.h"

void State::setContext(Context* context)
{
	this->_context_ = context;
}

Context::Context(State* state) : _state(nullptr)
{
	this->transitionTo(state);
}
Context::~Context()
{
	delete this->_state;
}

void Context::transitionTo(State* state)
{
	std::cout << "Context: Transition to " << typeid(*state).name() << std::endl;

	if (this->_state != nullptr)
		delete this->_state;

	this->_state = state;
	this->_state->setContext(this);
}
void Context::request1()
{
	this->_state->Handle1();
}
void Context::request2()
{
	this->_state->Handle2();
}
void ConcreteStateA::Handle1()
{
	std::cout << "ConcreteStateA handles request1." << std::endl;
	std::cout << "ConcreteStateA wants to change the state of the context." << std::endl;
	this->_context_->transitionTo(new ConcreteStateB());
}
void ConcreteStateA::Handle2()
{
	std::cout << "ConcreteStateA handles request2." << std::endl;
}
void ConcreteStateB::Handle1()
{
	std::cout << "ConcreteStateB handles request1." << std::endl;
}
void ConcreteStateB::Handle2()
{
	std::cout << "ConcreteStateB handles request2." << std::endl;
	std::cout << "ConcreteStateB wants to change the state of the context." << std::endl;
	this->_context_->transitionTo(new ConcreteStateA());
}
