#include<stdlib.h>
#include<pthread.h>
#include<iostream>
using namespace std;
pthread_mutex_t matmul;
int result[100][100];
int a[100][100] , b[100][100];
int r , c , n , m ;
void *thread_Multiply_Matrix(void *arg) {
	int i , j, k;
	long row = (long) arg;         // row to be computed
	for(j = 0 ; j < m; j++) {
		for(k = 0 ; k < c ;k++) {
			pthread_mutex_lock(&matmul);
			result[row][j]   += a[row][k] * b[k][j];
			pthread_mutex_unlock(&matmul);
			
		}
	}

	pthread_exit(NULL);
}
int main()
{
	int i , j ;
	cin>>r>>c;
	for(i = 0 ; i < r ;i++) 
		for(j = 0 ; j < c; j++) cin>>a[i][j];
	cin>>n>>m;
	for(i = 0 ; i < n ;i++) 
		for(j = 0 ; j < m; j++) cin>>b[i][j];
	pthread_mutex_init(&matmul , NULL);

	if(c == n) {
		int row = r ; int col = m;
		pthread_t threads[r+1];
		long NOT = (long) r;
		for(long t = 0 ; t < NOT ;t++) {
			pthread_create(&threads[t] , NULL , thread_Multiply_Matrix , (void *) t);

		}
		for( i = 0 ; i < r ;i++) {
			pthread_join(threads[i] , NULL);
		}
		cout<<"Result matrix :\n";
		for(i = 0 ; i < r ;i++) {
			for(j = 0 ; j < m; j++) cout<<result[i][j]<<" ";
			cout<<"\n";
		}
		pthread_exit(NULL);
	}
	else exit(1);
	return 0;
}
