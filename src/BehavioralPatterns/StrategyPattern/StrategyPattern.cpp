#include "StrategyPattern.h"

using namespace StrategyPattern;

Context::Context(Strategy* strategy) : _strategy(strategy)
{
}

void Context::set_strategy(Strategy* strategy)
{
	this->_strategy = strategy;
}
void Context::doSomeBusinessLogic() const
{
	std::cout << "Context : Sorting data using the strategy (not sure how it'll do it) " << std::endl;
	std::string res = this->_strategy->doAlgorithm(std::vector<std::string>{"a", "e", "c", "b", "d"});
	std::cout << res << std::endl;
}

std::string ConcreteStrategyA::doAlgorithm(const std::vector<std::string> &data) const
{
	std::string result;
	std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter){
		result += letter;
	});
	std::sort(std::begin(result), std::end(result));

	return result;
}

std::string ConcreteStrategyB::doAlgorithm(const std::vector<std::string> &data) const
{
	std::string result;
	std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter){
		result += letter;
	});
	std::sort(std::begin(result), std::end(result));
	for (unsigned int i = 0; i < result.size() / 2; i++)
	{
		std::swap(result[i], result[result.size() - i - 1]);
	}

	return result;
}
