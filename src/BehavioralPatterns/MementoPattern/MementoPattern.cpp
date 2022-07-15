#include "MementoPattern.h"

using namespace MementoPattern;

ConcreteMemento::ConcreteMemento(std::string& state) : _state(state)
{
	std::time_t now = std::time(0);
	this->_data = std::time(&now);
}
std::string ConcreteMemento::state() const
{
	return this->_state;
}
std::string ConcreteMemento::getName() const
{
	return this->_data + " / (" + this->_state.substr(0,9) + "...)";
}
std::string ConcreteMemento::data() const
{
	return this->_data;
}

Originator::Originator(std::string state) : _state(state)
{
	std::cout << "Originator : My initial state is : " << this->_state << std::endl;
}
void Originator::doSomeThing()
{
	std::cout << "Originator : I'm doing something important. " << std::endl;
	this->_state = this->_generateRandomString(30);
	std::cout << "Originator : and my state has changed to : " << this->_state << std::endl;
}
Memento* Originator::save()
{
	return new ConcreteMemento(this->_state);
}
void Originator::restore(Memento* memento)
{
	this->_state = memento->state();
	std::cout << "Originator : My state has changed to : " << this->_state << std::endl;
}
std::string Originator::_generateRandomString(int length)
{
	const char alphanum[] =
			"0123456789""ABCDEFGHIJKLMOPQRSTUVWXYZ""abcdefghijklmopqrstuvwxyz";
	int string_length = sizeof(alphanum) - 1;

	std::string random_string;
	for (int i = 0; i < length ; i++)
		random_string += alphanum[std::rand() & string_length];
	return random_string;
}
CareTaker::CareTaker(Originator* originator) : _originator(originator)
{
}
void CareTaker::backUp()
{
	std::cout << "\n Caretaker : Saving Originator's state.. " << std::endl;
	this->_mementos.push_back(this->_originator->save());
}
void CareTaker::undo()
{
	if (this->_mementos.empty() == true)
		return;
	Memento* memento = this->_mementos.back();
	this->_mementos.pop_back();
	std::cout << "CareTaker : Restoring state to : " << memento->getName() << std::endl;
	try
	{
		this->_originator->restore(memento);
	} catch (...)
	{
		this->undo();
	}
}
void CareTaker::showHistory() const
{
	std::cout << "Caretaker : Here's the list of mementos : " << std::endl;
	for (Memento* memento : this->_mementos)
		std::cout << memento->getName() << std::endl;
}
