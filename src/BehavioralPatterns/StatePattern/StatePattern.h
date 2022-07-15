#ifndef STATE_PATTERN_H
#define STATE_PATTERN_H

#include <iostream>
#include <typeinfo>

class Context;

class State
{
public:
	virtual ~State() = default;

	void setContext(Context* context);

	virtual void Handle1() = 0;
	virtual void Handle2() = 0;
protected:
	Context* _context_;
};

class Context
{
public:
	Context(State* state);
	~Context();

	void transitionTo(State* state);
	void request1();
	void request2();
private:
	State* _state;
};

class ConcreteStateA : public State // example) class RUN or STOP state : public State;
{
public:
	void Handle1() final;
	void Handle2() final;
};

class ConcreteStateB : public State
{
public:
	void Handle1() final;
	void Handle2() final;
};

#endif
