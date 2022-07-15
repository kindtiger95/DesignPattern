#ifndef CORPATTERN_H
#define CORPATTERN_H

#include <string>
#include <memory>

namespace CORPattern
{

class Handler
{
public:
	virtual ~Handler() = default;
	virtual Handler* setNext(Handler* handler) = 0;
	virtual std::string handle(std::string& request) = 0;
};

class AbstractHandler : public Handler
{
public:
	AbstractHandler();
	virtual Handler* setNext(Handler* handler) final;
	virtual std::string handle(std::string& request) override;

private:
	Handler* _nextHandler;
};

class FirstHandler : public AbstractHandler
{
public:
	using Ptr = std::unique_ptr<FirstHandler>;
	virtual std::string handle(std::string& request) final;
};

class SecondHandler : public AbstractHandler
{
public:
	using Ptr = std::unique_ptr<SecondHandler>;
	virtual std::string handle(std::string& request) final;
};

class ThirdHandler : public AbstractHandler
{
public:
	using Ptr = std::unique_ptr<ThirdHandler>;
	virtual std::string handle(std::string& request) final;
};

}

#endif
