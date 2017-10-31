#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
CRITICAL_SECTION CriticalSection;


//#include <pthread.h>


#include "CacheSimulator.h"

int main(void) {

	InitializeCriticalSection(&CriticalSection);
    threadInfo t1 = { 0 };
    threadInfo t2 = { 1 };
	threadInfo t3 = { 2 };
	threadInfo t4 = { 3 };

	HANDLE threads[4];
    //pthread_t thread1, thread2;

	threads[0] = CreateThread(NULL, 0, (void*)&readAddressTraces, (void*)&t1, 0, NULL);
	threads[1] = CreateThread(NULL, 0, (void*)&readAddressTraces, (void*)&t2, 0, NULL);
	threads[2] = CreateThread(NULL, 0, (void*)&readAddressTraces, (void*)&t3, 0, NULL);
	threads[3] = CreateThread(NULL, 0, (void*)&readAddressTraces, (void*)&t4, 0, NULL);

    //pthread_create(&thread1, NULL, (void*)&readAddressTraces, (void*)&t1);
    //pthread_create(&thread2, NULL, (void*)&readAddressTraces, (void*)&t2);


	WaitForMultipleObjects(ARRAYSIZE(threads), threads, TRUE, INFINITE);
	printf("Complete\n");

    //pthread_join(thread1, NULL);
    //pthread_join(thread2, NULL);

    printCacheMetrics();
	DeleteCriticalSection(&CriticalSection);
    return 0;
}
