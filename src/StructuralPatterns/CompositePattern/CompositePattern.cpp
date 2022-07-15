#include "CompositePattern.h"

using namespace CompositePattern;

void Component::setParent(Component* parent)
{
	this->_parent = parent;
}
Component* Component::getParent() const
{
	return this->_parent;
}
bool Component::isComposite() const
{
	return false;
}
std::string Leaf::operation() const
{
	return "Leaf";
}
void Composite::add(Component* component)
{
	this->_children.emplace_back(component);
	component->setParent(this);
}
void Composite::remove(Component* component)
{
	this->_children.remove(component);
	component->setParent(nullptr);
}
bool Composite::isComposite() const
{
	return true;
}
std::string Composite::operation() const
{
	std::string result;
	for (auto& it : this->_children)
		it == this->_children.back() ? result += it->operation() : result += it->operation() + "+";

	return "Branch(" + result + ")";
}
