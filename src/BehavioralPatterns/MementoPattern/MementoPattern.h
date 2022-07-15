#ifndef MEMENTOPATTERN_H
#define MEMENTOPATTERN_H

#include <string>
#include <memory>
#include <ctime>
#include <iostream>
#include <vector>

namespace MementoPattern
{

class Memento
{
public:
	virtual ~Memento() = default;
	virtual std::string getName() const = 0;
	virtual std::string data() const = 0;
	virtual std::string state() const = 0;
};

class ConcreteMemento : public Memento
{
public:
	ConcreteMemento(std::string& state);

	std::string state() const override;
	std::string getName() const override;
	std::string data() const override;

private:
	std::string _state;
	std::string _data;
};

class Originator
{
public:
	using Ptr = std::unique_ptr<Originator>;
	Originator(std::string state);
	void doSomeThing();
	Memento* save();
	void restore(Memento* memento);
private:
	std::string _state;
	std::string _random_string;

	std::string _generateRandomString(int length = 10);
};

class CareTaker
{
public:
	using Ptr = std::unique_ptr<CareTaker>;
	CareTaker(Originator* originator);
	void backUp();
	void undo();
	void showHistory() const;
private:
	std::vector<Memento*> _mementos;
	Originator* _originator;
};

}


#endif
