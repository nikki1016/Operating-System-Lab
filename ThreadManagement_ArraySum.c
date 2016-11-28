#include<pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define array_size 10
#define no_threads 5

int arr[array_size];
int gindex = 0;
int sum = 0;
pthread_mutex_t sum_mutex;

void *sumf(void *t){
	int lindex = 0;
	int partial_sum = 0;
	while(lindex < array_size ) {
		pthread_mutex_lock(&sum_mutex);
		lindex = gindex;
		gindex++;
		pthread_mutex_unlock(&sum_mutex);
		partial_sum += arr[lindex];
	}
	pthread_mutex_lock(&sum_mutex);
	sum += partial_sum;
	pthread_mutex_unlock(&sum_mutex);
	pthread_exit(NULL);
	
}
int main(int argc , char *argv[]) {

	int i ;
	pthread_mutex_init(&sum_mutex , NULL);
	pthread_t threads[no_threads];
	int tid[no_threads];
	for(i = 0 ; i < array_size ; i++)
		scanf("%d",&arr[i]);
	for(i = 0 ; i < no_threads ; i++) {
		tid[i] = i ;
		if(pthread_create(&threads[i] , NULL , sumf ,(void *) &tid[i] ) != 0 )
			perror("Pthread create fails");

	}
	for (i=0; i<5; i++) {
    		pthread_join(threads[i], NULL);
  	}
	printf("Sum of array is = %d\n" , sum);
  	pthread_mutex_destroy(&sum_mutex);
  	pthread_exit (NULL);
}
