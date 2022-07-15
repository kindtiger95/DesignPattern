#ifndef RWLOCK_H
#define RWLOCK_H

#include <mutex>
#include <condition_variable>

class RWLock
{
public:
	using Ptr = std::unique_ptr<RWLock>;

	static Ptr createPtr();

	virtual ~RWLock() = default;
	RWLock(const RWLock&) = delete;
	RWLock(RWLock&&) = delete;

	RWLock& operator = (const RWLock&) = delete;
	RWLock& operator = (RWLock&&) = delete;

	void rdlock();
	void wrlock();
	void unlock();

private:
	RWLock();

	int32_t _status;
	int32_t _waiting_readers;
	int32_t _waiting_writers;

	std::mutex _mutex;
	std::condition_variable _read_cv;
	std::condition_variable _write_cv;
};

#endif

