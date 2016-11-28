#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#define SIZE 10
int queue[SIZE];
int tail, head;
sem_t empty, fill;
void *producer(void *arg) 
{
	int v;	
	while(1)
	{
		sem_wait(&empty);
		queue[tail] = v;
		printf("produced: %d\n", v);
		v = rand() % 10;
		tail = (tail + 1)%SIZE;
		sem_post(&fill);
		sleep(4);
		
	}	
	pthread_exit(NULL);

}
void *consumer(void *arg)
{
	int v ;	
	while(1)
	{
		sem_wait(&fill);
		v = queue[head];
		printf("consumed: %d\n", v);
		head = (head + 1)%SIZE;
		sem_post(&empty);
		sleep(4);
		
	}	
	pthread_exit(NULL);

}
int main() 
{
	pthread_t prod , consum;
	srand(time(0));
	sem_init(&empty , 0 , 10);
	sem_init(&fill , 0 , 0);
	
	pthread_create(&prod , NULL , producer, NULL);
	pthread_create(&consum , NULL , consumer , NULL);

	pthread_join(prod , NULL);
	pthread_join(consum , NULL);

	sem_destroy(&empty);
	sem_destroy(&fill);
	
}
