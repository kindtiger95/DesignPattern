#ifndef BUILDERPATTERN_H
#define BUILDERPATTERN_H

#include <vector>
#include <iostream>
#include <string>
#include <memory>

class Product
{
public:
	using Ptr = std::unique_ptr<Product>;
	enum class Part { A, B, C };

	static Ptr createPtr();

	Product() = default;

	void partsList() const;
	bool push(const std::string& parts);

private:
	std::vector<std::string> _parts;
};

class Builder
{
public:
	using Ptr = std::unique_ptr<Builder>;

	static Ptr createPtr();

	Builder() = default;
	virtual ~Builder() = default;

	virtual void ProducePartA() = 0;
	virtual void ProducePartB() = 0;
	virtual void ProducePartC() = 0;

	virtual Product::Ptr getProduct() = 0;
};

class ConcreteBuilder
	: public Builder
{
public:
	ConcreteBuilder();
	virtual ~ConcreteBuilder() = default;

	virtual void ProducePartA() final;
	virtual void ProducePartB() final;
	virtual void ProducePartC() final;

	virtual Product::Ptr getProduct() final;

private:
	Product::Ptr _product;
};

class Director
{
public:
	Director() = default;
	virtual ~Director() = default;

	Product::Ptr buildLeastProduct() const;
	Product::Ptr buildMostProduct() const;
	Product::Ptr getCustomProduct(const std::vector<Product::Part>& part_list) const;
};

#endif
