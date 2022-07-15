#ifndef ITERATORPATTERN_H
#define ITERATORPATTERN_H

#include <iostream>
#include <string>
#include <vector>

namespace IteratorPattern
{
template <typename T, typename U>
class Iterator
{
public:
	typedef typename std::vector<T>::iterator iter_type;
	Iterator(U* p_data, bool reverse = false) : _m_p_data(p_data) { this->_m_it = this->_m_p_data->_m_data.begin(); }

	void first()
	{
		this->_m_it = this->_m_p_data->_m_data.begin();
	}
	void next()
	{
		this->_m_it++;
	}
	bool getDone()
	{
		return (this->_m_it == this->_m_p_data->_m_data.end());
	}
	iter_type current()
	{
		return this->_m_it;
	}

private:
	U* _m_p_data;
	iter_type _m_it;
};

template <typename T>
class Container
{
public:
	void Add(T a)
	{
		this->_m_data.push_back(a);
	}

	Iterator<T, Container>* createIterator()
	{
		return new Iterator<T, Container>(this);
	}
private:
	friend class Iterator<T, Container>;
	std::vector<T> _m_data;
};

class Data
{
public:
	Data(int a = 0) : _m_data(a) {}
	void set_data(int a)
	{
		this->_m_data = a;
	}
	int data()
	{
		return this->_m_data;
	}
private:
	int _m_data;
};

}

#endif
