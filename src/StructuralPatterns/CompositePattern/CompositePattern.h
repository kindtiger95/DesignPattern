#ifndef COMPOSITEPATTERN_H
#define COMPOSITEPATTERN_H

#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory>

namespace CompositePattern
{
class Component
{
public:
	using Ptr = std::unique_ptr<Component>;
	virtual ~Component() = default;
	void setParent(Component* parent);
	Component* getParent() const;

	virtual void add(Component* component) {};
	virtual void remove(Component* component) {};
	virtual bool isComposite() const;

	virtual std::string operation() const = 0;
protected:
	Component* _parent;
};

class Leaf : public Component
{
public:
	std::string operation() const final;
};

class Composite : public Component
{
public:
	void add(Component* component) final;
	void remove(Component* component) final;
	bool isComposite() const final;

	virtual std::string operation() const final;
protected:
	std::list<Component*> _children;
};
}

#endif
