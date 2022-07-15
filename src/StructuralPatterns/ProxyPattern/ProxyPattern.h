#ifndef PROXYPATTERN_H
#define PROXYPATTERN_H

#include <iostream>
#include <memory>
#include <utility>

namespace ProxyPattern
{

class Subject
{
public:
	virtual ~Subject() = default;
	virtual void request() const = 0;
};

class RealSubject : public Subject
{
public:
	using Ptr = std::unique_ptr<RealSubject>;
	virtual void request() const final;

};

class Proxy : public Subject
{
public:
	using Ptr = std::unique_ptr<Proxy>;
	Proxy(RealSubject::Ptr& real_subject);
	virtual ~Proxy();
	virtual void request() const final;
private:
	RealSubject::Ptr _realSubject;

	bool _checkAccess() const;
	void _logAccess() const;
};

}

#endif
