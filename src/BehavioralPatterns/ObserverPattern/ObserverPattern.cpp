#include "ObserverPattern.h"

using namespace ObserverPattern;

constexpr auto NOT_SET_VALUE = -1;
int Observer::_static_number = 0;

Subject::~Subject()
{
	std::cout << "Subject destroy." << std::endl;
}
void Subject::attach(IObserver* observer)
{
	this->_observerList.emplace_back(observer);
}
void Subject::detach(IObserver* observer)
{
	this->_observerList.remove(observer);
}
void Subject::notify()
{
	this->countObserver();

	for (auto& it : this->_observerList)
		it->update(this->_message);
}
void Subject::countObserver() const
{
	std::cout << "There are " << this->_observerList.size() << " observers in the list." << std::endl;
}
void Subject::createMessage(std::string message)
{
	this->_message = message;
	this->notify();
}
void Subject::someLogic()
{
	this->_message = "change message";
	this->notify();
	std::cout << "do Something important." << std::endl;
}
Observer::Observer(Subject& subject) : _subject(subject), _number(NOT_SET_VALUE)
{
	this->_subject.attach(this);
	std::cout << "I'm the Observer" << ++Observer::_static_number << std::endl;
	this->_number = Observer::_static_number;
}
Observer::~Observer()
{
	std::cout << "Observer destroy." << this->_number <<std::endl;
}
void Observer::update(const std::string& message)
{
	this->_message = message;
	this->printInfo();
}
void Observer::printInfo() const
{
	std::cout << "Observer : " << this->_number << "a new message is available -> " << this->_message << std::endl;
}
void Observer::removeMeFromTheList()
{
	this->_subject.detach(this);
	std::cout << "Observer : " << this->_number << " removed from the list. " << std::endl;
}
