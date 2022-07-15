#include "ObserverPattern.h"

#include <memory>
#include <utility>

using namespace ObserverPattern;

void ObserverPatternTest()
{
	using ObserverPtr = std::unique_ptr<ObserverPattern::Observer>;
	using SubjectPtr = std::unique_ptr<ObserverPattern::Subject>;

	SubjectPtr subject(new ObserverPattern::Subject());
	ObserverPtr observer1(new Observer(*subject));
	ObserverPtr observer2(new Observer(*subject));
	ObserverPtr observer3(new Observer(*subject));
	ObserverPtr observer4;
	ObserverPtr observer5;

	subject->createMessage("Create 1.");
	observer3->removeMeFromTheList();

	subject->createMessage("Create 2.");
	observer4.reset(new Observer(*subject));

	observer2->removeMeFromTheList();
	observer5.reset(new Observer(*subject));

	subject->createMessage("Create 3.");
	observer5->removeMeFromTheList();

	observer4->removeMeFromTheList();
	observer1->removeMeFromTheList();
}
