#ifndef PROTOTYPEPATTERN_H
#define PROTOTYPEPATTERN_H

#include <iostream>
#include <string>
#include <map>

class PrototypeFrame
{
public:
	PrototypeFrame(const std::string& prototype_name);

	virtual ~PrototypeFrame() {}
	virtual PrototypeFrame* Clone() const = 0;
	virtual void method(const float& prototype_field);

protected:
	std::string _prototype_name_;
	float _prototype_field_;
};

class ConcreteFrame1 : public PrototypeFrame
{
public:
	ConcreteFrame1(const std::string& prototype_name, const float& concrete_prototype_field);

	virtual PrototypeFrame* Clone() const final;
private:
	float _concrete_prototype_field1;
};

class ConcreteFrame2 : public PrototypeFrame
{
public:
	ConcreteFrame2(const std::string& prototype_name, const float& concrete_prototype_field);

	virtual PrototypeFrame* Clone() const final;
private:
	float _concrete_prototype_field2;
};

class PrototypeFactory
{
public:
	enum class Type
	{
		PROTOTYPE_1,
		PROTOTYPE_2
	};

	PrototypeFactory();
	~PrototypeFactory();

	PrototypeFrame* createPrototype(const Type& type);
private:
	std::map<Type, PrototypeFrame*> _prototypes;

};

#endif
