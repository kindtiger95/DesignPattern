#include "IteratorPattern.hpp"

using namespace IteratorPattern;

void IteratorPatternTest()
{
	std::cout << " _____Iterator with int_____ " << std::endl;
	Container<int> count;

	for (int i = 0; i < 10 ; i++)
	{
		count.Add(i);
	}

	Iterator<int, Container<int>>* it = count.createIterator();

	for (it->first(); !it->getDone(); it->next())
	{
		std::cout << *it->current() << std::endl;
	}

	Container<Data> count2;
	Data a(100), b(1000), c(10000);
	count2.Add(a);
	count2.Add(b);
	count2.Add(c);

	std::cout << " _____Iterator with Custom Class_____ " << std::endl;

	Iterator<Data, Container<Data>>* it2 = count2.createIterator();
	for (it2->first(); !it2->getDone(); it2->next())
	{
		std::cout << it2->current()->data() << std::endl;
	}
}
