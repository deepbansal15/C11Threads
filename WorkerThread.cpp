#include"WorkerThread.h"
#include <stdio.h>
void WorkerThread::Entry()
{
	int maxCount = 10000 / id;
	for (int idx = 0; idx < maxCount; idx++)
		printf("Hello from worker thread id : %d \n",id);
}
void WorkerThread::operator() ()
{
	Entry();
}