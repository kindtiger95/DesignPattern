#ifndef STRATEGYPATTERN_H
#define STRATEGYPATTERN_H

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <algorithm>

namespace StrategyPattern
{

class Strategy
{
public:
	virtual ~Strategy() = default;
	virtual std::string doAlgorithm(const std::vector<std::string>& data) const = 0;
};

class Context
{
public:
	using Ptr = std::unique_ptr<Context>;
	Context(Strategy* strategy = nullptr);
	virtual ~Context() = default;
	void set_strategy(Strategy* strategy);
	void doSomeBusinessLogic() const;
private:
	Strategy* _strategy;
};
class ConcreteStrategyA : public Strategy
{
public:
	using Ptr = std::unique_ptr<ConcreteStrategyA>;
    std::string doAlgorithm(const std::vector<std::string> &data) const override;
};
class ConcreteStrategyB : public Strategy
{
public:
	using Ptr = std::unique_ptr<ConcreteStrategyB>;
	std::string doAlgorithm(const std::vector<std::string> &data) const override;
};


}
#endif
