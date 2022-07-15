#include "SingletonPattern.h"

Singleton::Ptr Singleton::_instance;
std::mutex Singleton::_instanceLock;

Singleton::Singleton()
{
	this->_RWLock = RWLock::createPtr();
}
Singleton* Singleton::getInstance()
{
	std::lock_guard<std::mutex> guard(Singleton::_instanceLock);

	if(Singleton::_instance == nullptr)
		Singleton::_instance = Ptr(new Singleton());

	return Singleton::_instance.get();
}
void Singleton::somethingFunction(const std::string& value)
{
	this->_RWLock->wrlock();
	this->_value = value;
	this->_RWLock->unlock();

	this->_RWLock->rdlock();
	std::cout << "Value : " << this->_value << std::endl;
	this->_RWLock->unlock();
}
