#include "CORPattern.h"

using namespace CORPattern;

AbstractHandler::AbstractHandler() : _nextHandler(nullptr)
{
}
Handler* AbstractHandler::setNext(Handler* handler)
{
	this->_nextHandler = handler;
	return handler;
}
std::string AbstractHandler::handle(std::string& request)
{
	if (this->_nextHandler != nullptr)
		return this->_nextHandler->handle(request);

	return {};
}

std::string FirstHandler::handle(std::string& request)
{
	if (request == "one")
		return "I'm FirstHandler. " + request + "\n";
	else
		return AbstractHandler::handle(request);
}

std::string SecondHandler::handle(std::string& request)
{
	if (request == "two")
		return "I'm SecondHandler. " + request + "\n";
	else
		return AbstractHandler::handle(request);
}

std::string ThirdHandler::handle(std::string& request)
{
	if (request == "three")
		return "I'm ThirdHandler. " + request + "\n";
	else
		return AbstractHandler::handle(request);
}
