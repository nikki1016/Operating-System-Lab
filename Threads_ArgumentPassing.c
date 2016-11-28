#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
struct thread_data
{
   int	thread_id;
   int priority_value;
   char message;
};
void *Print(void *priority)
{
	long p = (long)priority;
	printf(" priotity of thread is%ld!\n", p);
	pthread_exit(NULL);
}
struct thread_data thread_data_array[5];
void *foo(void *threadarg)
{
	struct thread_data *data;
	data = (struct thread_data *) threadarg;
	int taskid = data->thread_id;
	int p = data->priority_value;
	char msg = data->message;
	printf("thread id is %d = , priority value is %d , and message is - %c \n",taskid , p , msg);
	pthread_exit(NULL);

}
int main() 
{
	pthread_t thread;
	int rc;
	int priority_val = 1;
	printf(" creating thread for single arg passing");
	rc = pthread_create(&thread, NULL, Print, (void *)priority_val);  // single arg passing 
	if (rc){
		printf("ERROR; return code from pthread_create() is %d\n", rc);
		exit(-1);
	}
	
	/* passing structure a argument */
	pthread_t threads[5];
	long t;
	for(t=0; t<5; t++){
		printf("In main: creating thread %ld\n", t);
		thread_data_array[t].thread_id = t;
		thread_data_array[t].priority_value = t+1;
		thread_data_array[t].message = t+95;
		rc = pthread_create(&threads[t], NULL,foo, (void *)&thread_data_array[t]);
		if (rc){
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}	
	}	      

	
	pthread_exit(NULL);

}
