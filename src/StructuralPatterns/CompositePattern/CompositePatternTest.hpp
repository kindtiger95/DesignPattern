#include "CompositePattern.h"

using namespace CompositePattern;

void CompositePatternTest()
{
	Component::Ptr simple(new Leaf());
	std::cout << "Client: I've got a simple component : " << std::endl;
	std::cout << "Result : " << simple->operation();
	std::cout << std::endl;

	Component::Ptr tree(new Composite());
	Component::Ptr branch1(new Composite());
	Component::Ptr branch2(new Composite());

	Component::Ptr leaf_1(new Leaf());
	Component::Ptr leaf_2(new Leaf());
	Component::Ptr leaf_3(new Leaf());

	branch1->add(leaf_1.get());
	branch1->add(leaf_2.get());

	branch2->add(leaf_3.get());

	tree->add(branch1.get());
	tree->add(branch2.get());

	std::cout << "Client: Now I've got a composite tree : " << std::endl;
	std::cout << "Result : " << tree->operation() << std::endl;

	std::cout << "Client: I don't need to check the components classes even when managing the tree : " << std::endl;
	if (tree->isComposite() == true)
		tree->add(simple.get());

	std::cout << "Result : " << tree->operation() << std::endl;
}
