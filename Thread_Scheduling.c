#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
void *Sum(void *tid) {
	long double i ;
	long t = (long)tid;
	float sum = 0.0;
	
	for(i = 1; i <= 10000;i++) {
		sum = sum + sin(i);
	}
	printf("result for thread with id %ld is %f\n",t , sum);
	sleep(4);
	pthread_exit(NULL);
}
int main() {
	int n = 32;
	pthread_t thread[32];
	long i ;
	for(i = 0 ; i < n;i++) {
		printf("Main: creating thread %ld\n", i);
		int rc = pthread_create(&thread[i], NULL, Sum, (void *)i);
		if (rc) {
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}
	
	pthread_exit(NULL);

	
}
