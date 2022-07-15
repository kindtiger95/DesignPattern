#include "MementoPattern.h"

using namespace MementoPattern;

void MementoPatternTest()
{
	Originator::Ptr originator(new Originator("Super-duper-puper-super."));
	CareTaker::Ptr caretaker(new CareTaker(originator.get()));

	caretaker->backUp();
	originator->doSomeThing();

	caretaker->backUp();
	originator->doSomeThing();

	caretaker->backUp();
	originator->doSomeThing();

	std::cout << std::endl;

	caretaker->showHistory();
	std::cout << "\n Client : Now, let's rollback! " << std::endl;
	caretaker->undo();
	std::cout << "\n Client : Once more. " << std::endl;
	caretaker->undo();

}
