#ifndef ABSTRACTFACTORYPATTERN_H
#define ABSTRACTFACTORYPATTERN_H

#include <string>
#include <memory>

class Abstract
{
public:
	using Ptr = std::unique_ptr<Abstract>;

	enum class Type {A, B};

	Abstract() = default;
	virtual ~Abstract() = default;

	virtual std::string function() const = 0;

	static Ptr createPtr(const Type& type);
};

class ConcreteA 
	: public Abstract
{
public:
	ConcreteA() = default;
	virtual ~ConcreteA() = default;

	virtual std::string function() const final;
};
class ConcreteB 
	: public Abstract
{
public:
	ConcreteB() = default;
	virtual ~ConcreteB() = default;

	virtual std::string function() const final;
};

#endif
