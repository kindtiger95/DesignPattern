#ifndef VISITORPATTERN_H
#define VISITORPATTERN_H

#include <iostream>
#include <string>

namespace VisitorPattern
{

class ConcreteComponentA;
class ConcreteComponentB;

class Visitor
{
public:
	virtual ~Visitor() = default;
	virtual void VisitConcreteComponentA(const ConcreteComponentA *element) const = 0;
	virtual void VisitConcreteComponentB(const ConcreteComponentB *element) const = 0;
};

class Component
{
public:
	virtual ~Component() = default;
	virtual void Accept(Visitor *visitor) const = 0;
};

class ConcreteComponentA : public Component
{
public:
	void Accept(Visitor *visitor) const override;
	std::string ExclusiveMethodOfConcreteComponentA() const;
};

class ConcreteComponentB : public Component
{
public:
	void Accept(Visitor *visitor) const override;
	std::string SpecialMethodOfConcreteComponentB() const;
};

class ConcreteVisitor1 : public Visitor
{
public:
	void VisitConcreteComponentA(const ConcreteComponentA *element) const override;
	void VisitConcreteComponentB(const ConcreteComponentB *element) const override;
};

class ConcreteVisitor2 : public Visitor
{
public:
	void VisitConcreteComponentA(const ConcreteComponentA *element) const override;
	void VisitConcreteComponentB(const ConcreteComponentB *element) const override;
};

}

#endif
