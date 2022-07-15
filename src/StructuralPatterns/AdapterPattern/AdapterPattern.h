#ifndef ADAPTERPATTERN_H_
#define ADAPTERPATTERN_H_

#include <iostream>
#include <algorithm>
#include <utility>

namespace AdapterPattern
{
class Target
{
public:
	virtual ~Target() = default;

	virtual std::string request() const;

};
class Adaptee
{
public:
	std::string specificRequest() const;
};
class Adapter : public Target
{
public:
	Adapter(Adaptee* adaptee);
	virtual std::string request() const final;
private:
	Adaptee* _adaptee;
};
}
#endif
