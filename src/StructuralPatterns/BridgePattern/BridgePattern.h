#ifndef BRIDGEPATTERN_H
#define BRIDGEPATTERN_H

#include <string>
#include <iostream>

namespace BridgePattern
{
class Implementation
{
public:
	Implementation() = default;
	virtual ~Implementation() = default;
	virtual std::string operationImple() const= 0;
};

class ConcreteImplementationA : public Implementation
{
public:
	std::string operationImple() const final;
};

class ConcreteImplementationB : public Implementation
{
public:
	std::string operationImple() const final;
};

class Abstraction
{
public:
	Abstraction(Implementation* implementation);
	virtual ~Abstraction() = default;
	virtual std::string operation() const;
protected:
	Implementation* _imple;
};

class ExtendedAbstraction : public Abstraction
{
public:
	ExtendedAbstraction(Implementation* implementation);
	virtual std::string operation() const final;
};
}



#endif
