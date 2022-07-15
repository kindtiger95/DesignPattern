#include "RWLock.h"

RWLock::RWLock() : _status(0), _waiting_readers(0), _waiting_writers(0)
{
}

void RWLock::rdlock()
{
	std::unique_lock<std::mutex> lock(this->_mutex);
	this->_waiting_readers += 1;
	this->_read_cv.wait(lock, [&]() { return _waiting_writers == 0 && _status >= 0; });
	this->_waiting_readers -= 1;
	this->_status += 1;
}
void RWLock::wrlock()
{
    std::unique_lock<std::mutex> lock(this->_mutex);
    this->_waiting_writers += 1;
    this->_write_cv.wait(lock, [&]() { return _status == 0; });
    this->_waiting_writers -= 1;
    this->_status = -1;
}
void RWLock::unlock()
{
    std::unique_lock<std::mutex> lock(this->_mutex);
    this->_status == -1 ? this->_status = 0 : this->_status -= 1;
    if (_waiting_writers > 0)
    {
        if (_status == 0)
            this->_write_cv.notify_one();
    }
    else
    {
        this->_read_cv.notify_all();
    }
}
RWLock::Ptr RWLock::createPtr()
{
	return RWLock::Ptr(new RWLock());
}
