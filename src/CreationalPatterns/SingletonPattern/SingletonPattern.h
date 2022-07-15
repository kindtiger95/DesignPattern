#ifndef SINGLETONPATTERN_H
#define SINGLETONPATTERN_H

#include "RWLock.h"

#include <iostream>
#include <string>
#include <memory>
#include <mutex>

class Singleton
{
public:
	using Ptr = std::unique_ptr<Singleton>;

	virtual ~Singleton() = default;

	static Singleton* getInstance();

	void somethingFunction(const std::string& value);

private:
	Singleton();

	static Ptr _instance;
	static std::mutex _instanceLock;

	RWLock::Ptr _RWLock;
	std::string _value;
};

#endif
