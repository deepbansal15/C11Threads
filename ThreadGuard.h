#ifndef _THREAD_GUARD_H
#define _THREAD_GUARD_H
#include<thread>
class ThreadGuard
{
public:
	ThreadGuard(std::thread& t) : thread(t){}
	~ThreadGuard()
	{
		if (thread.joinable())
			thread.join();
	}
private:
	std::thread& thread;

	ThreadGuard(const ThreadGuard&) = delete;
	ThreadGuard& operator=(const ThreadGuard&) = delete;
};
#endif