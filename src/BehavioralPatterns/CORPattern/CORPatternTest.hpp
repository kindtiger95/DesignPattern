#include "CORPattern.h"

#include <string>
#include <vector>

using namespace CORPattern;

void _testcode(Handler* handler)
{
	std::vector<std::string> number = {"one", "two", "four"};
	for (auto& it : number)
	{
		std::cout << "Client Who wants a " << it << "?\n";
		const std::string res = handler->handle(it);
		res.empty() == false ? std::cout << " " << res : std::cout << " " << it << " was left untouched. \n";
	}
}

void CORPatternTest()
{
	CORPattern::FirstHandler::Ptr first(new FirstHandler);
	CORPattern::SecondHandler::Ptr second(new SecondHandler);
	CORPattern::ThirdHandler::Ptr third(new ThirdHandler);

	first->setNext(second.get())->setNext(third.get());
	std::cout << "Chain : first > second > third \n";
	_testcode(first.get());


	std::cout << "\n";
	std::cout << "Subchain: second > third \n";
	_testcode(second.get());
}

