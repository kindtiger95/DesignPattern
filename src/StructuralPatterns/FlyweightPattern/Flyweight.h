#ifndef FLYWEIGHTPATTERN_H
#define FLYWEIGHTPATTERN_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>

/*
 * It is assumed that this class has too much data.
 * Since there is a lot of vehicle data,
 * create a new class with some of the member variables of this class and have an instance in the class.
 */

class Flyweight
{
public:
	using ID = unsigned int;
	using Ptr = std::unique_ptr<Flyweight>;

	Flyweight() = default;
	virtual ~Flyweight() = default;

	virtual bool operation(const std::string& input) = 0;
};

class SharedFlyweightA
	: public Flyweight
{
public:
	SharedFlyweightA() { std::cout << "create A" << std::endl; };
	virtual ~SharedFlyweightA() { std::cout << "delete A" << std::endl; };

	bool operation(const std::string& input) override;
};

class SharedFlyweightB
	: public Flyweight
{
public:
	SharedFlyweightB() { std::cout << "create B" << std::endl; };
	virtual ~SharedFlyweightB() { std::cout << "delete B" << std::endl; };

	bool operation(const std::string& input) override;
};

class SharedFlyweightC
	: public Flyweight
{
public:
	SharedFlyweightC() { std::cout << "create C" << std::endl; };
	virtual ~SharedFlyweightC() { std::cout << "delete C" << std::endl; };

	bool operation(const std::string& input) override;
};

/* not used */
class UnsharedFlyweight
	: public Flyweight
{
public:
	UnsharedFlyweight() = default;
	virtual ~UnsharedFlyweight() = default;

	bool operation(const std::string& input) override;
};

class FlyweightFactory
{
public:
	using ID = Flyweight::ID;

	FlyweightFactory() = default;
	virtual ~FlyweightFactory() = default;

	template<typename T = SharedFlyweightA>
	Flyweight* getFlyweight(const ID& id)
	{
		if (this->_flyweightList.count(id) <= 0)
			this->_flyweightList.emplace(id, Flyweight::Ptr(new T()));

		return this->_flyweightList.at(id).get();
	}

	bool isExistFlyweight(const ID& id) const
	{
		return this->_flyweightList.count(id) > 0;
	}
	std::size_t removeFlyweight(const ID& id)
	{
		return this->_flyweightList.erase(id);
	}
	std::vector<ID> getList() const
	{
		std::vector<ID> ret;
		for (const auto& element : this->_flyweightList)
			ret.emplace_back(element.first);

		return ret;
	}

private:
	std::map<ID, Flyweight::Ptr> _flyweightList;
};

std::ostream& operator<<(std::ostream& os, const FlyweightFactory& fly_factory);

#if 0
class CarFactory;

class InterSectionObserver
{
public:
	InterSectionObserver();
	CarFactory* getFactory() const;

private:
	std::unique_ptr<CarFactory> _factory;
//	Car _carObject;
//	std::unordered_map<std::string, Car> _carMap;
	std::string _signal;
	int _carCount;
	int _signalViolationCount;
	bool _isExistSignalViolation;
};
// instance Class (shared)
class Car
{
public:
	Car(const std::string& type);

	void setX(const int& x);
	void setY(const int& y);

	void getPosition() const;
private:

	int _x;
	int _y;

	std::string _type;
	std::string _color;
	int _carNumber;
	int _carLength;
	bool _isStart;
};

class CarFactory //FlyweightFactory
{
public:
	CarFactory() = default;
	Car getCar(const std::string& type);
private:
	std::unordered_map<std::string, Car> _carMap;
};
#endif

#endif /* FLYWEIGHTPATTERN_H */
