#ifndef _WORKER_THREAD_H
#define _WORKER_THREAD_H
#include<thread>
class WorkerThread
{
public:
	void Entry();
	void operator() ();
	unsigned int id;
};
#endif