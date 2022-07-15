#include "ProxyPattern.h"

using namespace ProxyPattern;

void ProxyPatternTest()
{
	std::cout << "Client: Executing the client code with a real subject:" << std::endl;
	ProxyPattern::RealSubject::Ptr real_subject(new RealSubject());
	real_subject->request();
	std::cout << std::endl;

	std::cout << "Client: Executing the same client code with a proxy:" << std::endl;
	ProxyPattern::Proxy::Ptr proxy(new Proxy(real_subject));
	proxy->request();

}
