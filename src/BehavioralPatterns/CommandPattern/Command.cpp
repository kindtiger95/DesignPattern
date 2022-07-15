#include "Command.h"

using namespace CommandPattern;

SimpleCommand::SimpleCommand(std::string payload) : _payload(payload)
{
}
void SimpleCommand::execute() const
{
	std::cout << "SimpleCommand: See, I can do simple things like printing (" << this->_payload << ")" << std::endl;
}
void Receiver::doSomething(const std::string& a)
{
	std::cout << "Receiver: Working on (" << a << ".)" << std::endl;
}
void Receiver::doSomethingElse(const std::string& b)
{
	std::cout << "Receiver: Also Working on (" << b << ".)" << std::endl;
}

ComplexCommand::ComplexCommand(Receiver* receiver, std::string a, std::string b) : _receiver(receiver), _a(a), _b(b)
{
}
void ComplexCommand::execute() const
{
	std::cout << "ComplexCommand: Complex stuff should be done by a receiver object." << std::endl;
	this->_receiver->doSomething(this->_a);
	this->_receiver->doSomethingElse(this->_b);
}
void Caller::setOnStart(Command* command)
{
	this->_onStart = command;
}
void Caller::setOnFinish(Command* command)
{
	this->_onFinish = command;
}
void Caller::doSomethingImportant()
{
	std::cout << "Invoker: Does anybody want something done before I begin? " << std::endl;
	if (this->_onStart != nullptr)
		this->_onStart->execute();

	std::cout << "Invoker: ...doing something really important..." << std::endl;
	std::cout << "Invoker: Does anybody want something done after I finish?" << std::endl;

	if (this->_onFinish != nullptr)
		this->_onFinish->execute();
}
