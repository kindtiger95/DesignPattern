#ifndef FACTORY_METHOD_PATTERN_H
#define FACTORY_METHOD_PATTERN_H

#include <iostream>
#include <memory>
#include <utility>

namespace FactoryMethod
{
class Product
{
public:
	virtual ~Product() = default;
	virtual std::string operation() const = 0;
};

class ConcreteProduct1 : public Product
{
public:
	virtual std::string operation() const final;
};

class ConcreteProduct2 : public Product
{
public:
	virtual std::string operation() const final;
};

class Creator
{
public:
	virtual ~Creator() = default;
	virtual Product* factoryMethod() const = 0;
	std::string someOperation() const;
};

class ConcreteCreator1 : public Creator
{
public:
	Product* factoryMethod() const final;
};

class ConcreteCreator2 : public Creator
{
public:
	Product* factoryMethod() const final;
};
}
#endif
