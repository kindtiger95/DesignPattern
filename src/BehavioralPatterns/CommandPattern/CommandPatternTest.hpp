#include "Command.h"

/* 	Command Pattern
*	Separate Functions :
*		Object <-> Command Realize <-> Command Interface <-> command calling
*/

using namespace CommandPattern;

void CommandPatternTest()
{
	Caller::Ptr caller(new Caller);
	Command::Ptr simple(new SimpleCommand("Say Hi"));
	Receiver::Ptr receiver(new Receiver);
	Command::Ptr complex(new ComplexCommand(receiver.get(), "Send email", "Save report"));

	caller->setOnStart(simple.get());
	caller->setOnFinish(complex.get());
	caller->doSomethingImportant();
}
