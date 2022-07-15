#include "BuilderPattern.h"

void BuilderPatternTest()
{
	Director director;

	std::cout << "Standard basic product." << std::endl;
	auto basic = director.buildLeastProduct();
	basic->partsList();

	std::cout << "Standard full product." << std::endl;
	auto full = director.buildMostProduct();
	full->partsList();

	std::cout << "Custom product." << std::endl;
	auto custom_1 = director.getCustomProduct({ Product::Part::A, Product::Part::C, Product::Part::B, Product::Part::A });
	custom_1->partsList();

	auto custom_2 = director.getCustomProduct({ Product::Part::C, Product::Part::C, Product::Part::B, Product::Part::A, Product::Part::B });
	custom_2->partsList();
}
