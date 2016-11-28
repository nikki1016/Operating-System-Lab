#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define no_thread 2

int count = 0;
pthread_mutex_t count_mutex;
pthread_cond_t count_nonzero;
void *inc_count(void *t) {
	long id = (long)t;
	pthread_mutex_lock(&count_mutex);
	 if (count == 0)
       pthread_cond_signal(&count_nonzero); 
     count = count + 1;
	printf("Thread %ld updated count as %d\n",id , count);
	pthread_mutex_unlock(&count_mutex);	
	
}
void *dec_count(void *t) {
	long id = (long)t;
	pthread_mutex_lock(&count_mutex);
	if(count == 0)
		pthread_cond_wait(&count_nonzero, &count_mutex);
	count -= 1; 
	printf("Thread %ld updated count as %d\n",id , count);
	pthread_mutex_unlock(&count_mutex);
	
}
int main() 
{
	pthread_t threads[no_thread];
	int tid[no_thread] ;
	tid[0] = 1;
	tid[1] = 2;
	int i ;
	pthread_create(&threads[0] ,NULL , inc_count , (void*)tid[0]);
	pthread_create(&threads[1] ,NULL , dec_count ,(void*)tid[1]);
	for( i = 0 ; i < no_thread ; i++) 
		pthread_join(threads[i] ,NULL);
	
	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&count_nonzero);
	pthread_exit(NULL);
}
