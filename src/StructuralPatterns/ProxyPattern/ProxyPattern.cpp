#include "ProxyPattern.h"

using namespace ProxyPattern;

void RealSubject::request() const
{
	std::cout << "RealSubject : Handling request. " << std::endl;
}

Proxy::Proxy(ProxyPattern::RealSubject::Ptr& real_subject)
{
	this->_realSubject = std::move(real_subject);
}
Proxy::~Proxy()
{

}
void Proxy::request() const
{
	if (this->_checkAccess() == true)
	{
		this->_realSubject->request();
		this->_logAccess();
	}
}
bool Proxy::_checkAccess() const
{
	std::cout << "Proxy: Checking access prior to firing a real request. " << std::endl;
	return true;
}
void Proxy::_logAccess() const
{
	std::cout << "Proxy: Logging the time of request. " << std::endl;
}
