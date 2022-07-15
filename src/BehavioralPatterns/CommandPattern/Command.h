#ifndef COMMANDPATTERN_H_
#define COMMANDPATTERN_H_

#include <iostream>
#include <memory>
#include <string>

namespace CommandPattern
{

class Command
{
public:
	using Ptr = std::unique_ptr<Command>;
	virtual ~Command() = default;
	virtual void execute() const = 0;
};

class SimpleCommand : public Command
{
public:
	explicit SimpleCommand(std::string paylod);
	void execute() const override;
private:
	std::string _payload;
};

class Receiver
{
public:
	using Ptr = std::unique_ptr<Receiver>;
	Receiver() = default;
	void doSomething(const std::string& a);
	void doSomethingElse(const std::string& b);
};

class ComplexCommand : public Command
{
public:
	ComplexCommand(Receiver* receiver, std::string a, std::string b);
	void execute() const override;
private:
	Receiver* _receiver;
	std::string _a;
	std::string _b;
};

class Caller
{
public:
	using Ptr = std::unique_ptr<Caller>;
	virtual ~Caller() = default;
	void setOnStart(Command* command);
	void setOnFinish(Command* command);
	void doSomethingImportant();
private:
	Command* _onStart;
	Command *_onFinish;
};

}
#endif
