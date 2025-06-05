#include <pthread.h>
#include <stdio.h>

int var = 0;

void *thread_func(void *arg) {
	for (int i = 0; i < 1000000; ++i)
		var++;
	return NULL;
}

int main() {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, thread_func, NULL);
	pthread_create(&t2, NULL, thread_func, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("var = %d\n", var);
	return 0;
}

