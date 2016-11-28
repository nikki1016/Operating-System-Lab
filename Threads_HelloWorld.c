#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *print_hello(void *threadid) {
	printf("hello world from thread %ld\n",(long)threadid);
	pthread_exit(NULL);	
}
int main(int argc ,char *argv[]) {

	int n =10;
	pthread_t threads[n];
	int i ;
	for(i = 0; i < n ; i++) {
		printf("In main: creating thread %d\n", i);
		int t = pthread_create(&threads[i],NULL ,print_hello ,(void*)i);	
		if(t) {
			printf("ERROR creating thread with return code %d",t);
			exit(-1);		
		}	


	}
	pthread_exit(NULL);	


}
