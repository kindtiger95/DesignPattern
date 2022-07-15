#include "SingletonPattern.h"

#include <chrono>
#include <thread>

void Thread1()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		Singleton::getInstance()->somethingFunction("thread 1");
	}
}
void Thread2()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		Singleton::getInstance()->somethingFunction("thread 2");
	}
}

void SingletonPatternTest()
{
	std::thread t1(Thread1);
	std::thread t2(Thread2);

	std::this_thread::sleep_for(std::chrono::milliseconds(500000));

	if (t1.joinable() == true)
		t1.join();

	if (t2.joinable() == true)
		t2.join();
}
