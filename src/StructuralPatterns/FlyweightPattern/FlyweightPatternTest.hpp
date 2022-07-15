#include "Flyweight.h"

#if 0
#include <vector>
#include <random>

std::string getRandomType()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 4);
	std::vector<std::string> list = {"bus", "car", "truck", "special_car", "motocycle"};
	return list[dis(gen)];
}

int getRandomX()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 99);
	return dis(gen);
}

int getRandomY()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 99);
	return dis(gen);
}

void FlyweightPatternTest()
{
	InterSectionObserver Observer;
	for (int i = 0; i < 20; i++)
	{
		Car car = Observer.getFactory()->getCar(getRandomType());
		car.setX(getRandomX());
		car.setY(getRandomY());
		car.getPosition();
	}
}
#endif
void FlyweightPatternTest()
{
	FlyweightFactory factory;

	/* Test Create */
	auto flyweight_object_1 = factory.getFlyweight<SharedFlyweightA>(1);
	flyweight_object_1->operation("input message");
	auto flyweight_object_2 = factory.getFlyweight<SharedFlyweightB>(2);
	flyweight_object_2->operation("input message");
	auto flyweight_object_3 = factory.getFlyweight<SharedFlyweightC>(3);
	flyweight_object_3->operation("input message");
	auto flyweight_object_4 = factory.getFlyweight<>(4);
	flyweight_object_4->operation("input message");

	/* Test Overlap Create*/
	auto flyweight_object_5 = factory.getFlyweight<SharedFlyweightA>(1);
	flyweight_object_5->operation("input message");
	auto flyweight_object_6= factory.getFlyweight<SharedFlyweightB>(1);
	flyweight_object_6->operation("input message");


	/* Test Exist Check */
	std::string is_exist = factory.isExistFlyweight(1) ? "exist" : "not exist";
	std::cout << "id 1 is " << is_exist << std::endl;
	
	/* Test get list */
	auto list = factory.getList();
	std::cout << "List : ";
	for (const auto& id : list)
		std::cout << id << " ";
	std::cout << std::endl;

	/* Test remove */
	factory.removeFlyweight(1);

	is_exist = factory.isExistFlyweight(1) ? "exist" : "not exist";
	std::cout << "id 1 is " << is_exist << std::endl;

	/* Test cout operator */
	std::cout << factory << std::endl;
}
