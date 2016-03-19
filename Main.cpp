#include<thread>
#include<stdio.h>
#include"WorkerThread.h"
#include"ThreadGuard.h"
int main()
{
	WorkerThread wt;
	for (int idx = 0; idx < 10; idx++)
	{
		wt.id = idx+1;
		std::thread t(wt);
		t.join();
		//t.detach();
	}
	//std::thread t(wt);
	//ThreadGuard tg(t);
	unsigned int threadCount = std::thread::hardware_concurrency();
	return 0;
}