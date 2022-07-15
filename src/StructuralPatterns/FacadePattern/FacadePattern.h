#ifndef FACADEPATTERN_H
#define FACADEPATTERN_H

#include <string>
#include <memory>
#include <utility>

namespace FacadePattern
{
class Subsystem1
{
public:
	using Ptr = std::unique_ptr<Subsystem1>;
	std::string operation1() const;
	std::string operationN() const;
};

class Subsystem2
{
public:
	using Ptr = std::unique_ptr<Subsystem2>;
	std::string operation1() const;
	std::string operationZ() const;
};

class Facade
{
public:
	using Ptr = std::unique_ptr<Facade>;
	Facade(Subsystem1* subsystem1 = nullptr,
			Subsystem2* subsystem2 = nullptr);
	virtual ~Facade() = default;
	std::string operation();
protected:
	Subsystem1* _subsystem1;
	Subsystem2* _subsystem2;
};

}
#endif
