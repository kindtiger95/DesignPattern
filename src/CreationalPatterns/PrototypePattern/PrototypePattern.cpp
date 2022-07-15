#include "PrototypePattern.h"

constexpr float NOT_SET_VALUE = -1;

PrototypeFrame::PrototypeFrame(const std::string& prototype_name) : _prototype_name_(prototype_name), _prototype_field_(NOT_SET_VALUE)
{
}
void PrototypeFrame::method(const float& _prototype_field_)
{
	this->_prototype_field_ = _prototype_field_;
	std::cout << "Call Method from " << this->_prototype_name_ << " with field " << this->_prototype_field_ << std::endl;
}

ConcreteFrame1::ConcreteFrame1(const std::string& prototype_name, const float& concrete_prototype_field) :
		PrototypeFrame(prototype_name), _concrete_prototype_field1(concrete_prototype_field)
{
}
PrototypeFrame* ConcreteFrame1::Clone() const
{
	return new ConcreteFrame1(*this);
}

ConcreteFrame2::ConcreteFrame2(const std::string& prototype_name, const float& concrete_prototype_field) :
		PrototypeFrame(prototype_name), _concrete_prototype_field2(concrete_prototype_field)
{
}
PrototypeFrame* ConcreteFrame2::Clone() const
{
	return new ConcreteFrame2(*this);
}
PrototypeFactory::PrototypeFactory()
{
	this->_prototypes[Type::PROTOTYPE_1] = new ConcreteFrame1("PROTOTYPE_1", 50.f);
	this->_prototypes[Type::PROTOTYPE_2] = new ConcreteFrame1("PROTOTYPE_2", 60.f);
}
PrototypeFactory::~PrototypeFactory()
{
	delete this->_prototypes[Type::PROTOTYPE_1];
	delete this->_prototypes[Type::PROTOTYPE_2];
}
PrototypeFrame* PrototypeFactory::createPrototype(const Type& type)
{
	return this->_prototypes[type]->Clone();
}
