#include "BuilderPattern.h"
#include <utility>

Product::Ptr Product::createPtr()
{
	return Ptr(new Product());
}
void Product::partsList() const
{
	std::cout << "Product parts : ";
	for (int i = 0; i < static_cast<int>(this->_parts.size()); i++)
	{
		std::cout << this->_parts[i];
		if(i != static_cast<int>(this->_parts.size()) - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}
bool Product::push(const std::string& parts)
{
	if (parts.empty())
		return false;

	this->_parts.emplace_back(parts);

	return true;
}
Builder::Ptr Builder::createPtr()
{
	return Ptr(new ConcreteBuilder());
}
ConcreteBuilder::ConcreteBuilder()
{
	this->_product = Product::createPtr();
}
void ConcreteBuilder::ProducePartA()
{
	this->_product->push("Part A1");
}
void ConcreteBuilder::ProducePartB()
{
	this->_product->push("Part B1");
}
void ConcreteBuilder::ProducePartC()
{
	this->_product->push("Part C1");
}
Product::Ptr ConcreteBuilder::getProduct()
{
	return std::move(this->_product);
}
Product::Ptr Director::buildLeastProduct() const
{
	auto builder = Builder::createPtr();
	
	builder->ProducePartA();

	return std::move(builder->getProduct());
}
Product::Ptr Director::buildMostProduct() const
{
	return this->getCustomProduct({ Product::Part::A, Product::Part::B, Product::Part::C });
}
Product::Ptr Director::getCustomProduct(const std::vector<Product::Part>& part_list) const
{
	auto builder = Builder::createPtr();
	for (const auto& part : part_list)
	{
		switch (part)
		{
		case Product::Part::A: builder->ProducePartA(); break;
		case Product::Part::B: builder->ProducePartB(); break;
		case Product::Part::C: builder->ProducePartC(); break;
		default: break;
		}
	}

	return std::move(builder->getProduct());
}
