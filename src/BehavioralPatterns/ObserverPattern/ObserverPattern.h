#ifndef OBSERVERPATTERN_H
#define OBSERVERPATTERN_H

#include <iostream>
#include <list>
#include <string>

namespace ObserverPattern
{
// interface
class IObserver
{
public:
	virtual ~IObserver(){};
	virtual void update(const std::string& message) = 0;
};

// interface
class ISubject
{
public:
	virtual ~ISubject(){};
	virtual void attach(IObserver* observer) = 0;
	virtual void detach(IObserver* observer) = 0;
	virtual void notify() = 0;
};

class Subject : public ISubject
{
public:
	virtual ~Subject();
	virtual void attach(IObserver* observer) final;
	virtual void detach(IObserver* observer) final;
	virtual void notify() final;

	void countObserver() const;
	void createMessage(std::string message = "Empty");
	void someLogic();

private:
	std::list<IObserver*> _observerList;
	std::string _message;
};

class Observer : public IObserver
{
public:
	Observer(Subject& subject);
	virtual ~Observer();
	virtual void update(const std::string& message) final;
	void printInfo() const;
	void removeMeFromTheList();
private:
	Subject& _subject;
	static int _static_number;
	int _number;
	std::string _message;
};
}
#endif
