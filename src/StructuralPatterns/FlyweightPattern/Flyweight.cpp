#include "Flyweight.h"

bool SharedFlyweightA::operation(const std::string& input)
{
	std::cout << "[A] Shared Flyweight : " << input << std::endl;

	return true;
}
bool SharedFlyweightB::operation(const std::string& input)
{
	std::cout << "[B] Shared Flyweight : " << input << std::endl;

	return true;
}
bool SharedFlyweightC::operation(const std::string& input)
{
	std::cout << "[C] Shared Flyweight : " << input << std::endl;

	return true;
}

bool UnsharedFlyweight::operation(const std::string& input)
{
	std::cout << "Unshared Flyweight : " << input << std::endl;

	return true;
}

std::ostream& operator<<(std::ostream& os, const FlyweightFactory& fly_factory)
{
	auto list = fly_factory.getList();
	std::cout << "FlyweightFactory List : ";
	for (const auto& id : list)
		std::cout << id << " ";

	return os;
}

#if 0
constexpr int NOT_SET_VALUE = -1;

InterSectionObserver::InterSectionObserver() 
	: _factory(new CarFactory()), _carCount(NOT_SET_VALUE),
		_signalViolationCount(NOT_SET_VALUE), _isExistSignalViolation(false)
{

}
CarFactory* InterSectionObserver::getFactory() const
{
	return this->_factory.get();
}
Car::Car(const std::string& type) 
	: _x(NOT_SET_VALUE), _y(NOT_SET_VALUE),
		_type(type), _carNumber(NOT_SET_VALUE), _carLength(NOT_SET_VALUE), _isStart(false)

{

}

void Car::setX(const int& x)
{
	this->_x = x;
}
void Car::setY(const int& y)
{
	this->_y = y;
}

void Car::getPosition() const
{
	std::cout << "this Car position : (" << this->_x << "," << this->_y << ") Type : " << this->_type << std::endl;
}

Car CarFactory::getCar(const std::string& type)
{
	auto it = this->_carMap.find(type);
	if (it == this->_carMap.end())
	{
		Car car(type);
		this->_carMap.insert(std::pair<std::string, Car>(type, car));
		std::cout << "Create New Car : " << type << std::endl;
		return car;
	}
	return it->first;
}

#endif