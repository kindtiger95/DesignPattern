#include "FactoryMethodPattern.h"

std::string FactoryMethod::ConcreteProduct1::operation() const
{
	return "Result of the ConcreteProduct1";
}
std::string FactoryMethod::ConcreteProduct2::operation() const
{
	return "Result of the ConcreteProduct2";
}
std::string FactoryMethod::Creator::someOperation() const
{
	std::unique_ptr<Product> product(this->factoryMethod());
	std::string res = "Creator: The same creator's code has just worked with " + product->operation();
	return res;
}
FactoryMethod::Product* FactoryMethod::ConcreteCreator1::factoryMethod() const
{
	return new ConcreteProduct1();
}
FactoryMethod::Product* FactoryMethod::ConcreteCreator2::factoryMethod() const
{
	return new ConcreteProduct2();
}
