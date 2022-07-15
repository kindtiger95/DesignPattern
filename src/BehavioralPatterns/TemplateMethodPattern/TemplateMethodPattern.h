#ifndef TEMPLATEMETHODPATTERN_H
#define TEMPLATEMETHODPATTERN_H

#include <iostream>
#include <memory>

namespace TemplateMethodPattern
{
class AbstractClass
{
public:
	AbstractClass() = default;
	virtual ~AbstractClass() = default;
	void templateMethod() const;
protected:
	void baseOperation1() const;
	void baseOperation2() const;
	void baseOperation3() const;

	virtual void requireOperations1() const = 0;
	virtual void requireOperations2() const = 0;

	virtual void Hook1() const {};
	virtual void Hook2() const {};
};

class ConcreteClass1 : public AbstractClass
{
public:
	using Ptr = std::unique_ptr<ConcreteClass1>;
protected:

	void requireOperations1() const override;
	void requireOperations2() const override;
};

class ConcreteClass2 : public AbstractClass
{
public:
	using Ptr = std::unique_ptr<ConcreteClass2>;
protected:
	void requireOperations1() const override;
	void requireOperations2() const override;
	void Hook1() const override;
};


}
#endif
