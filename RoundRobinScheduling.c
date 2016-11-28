#include<stdio.h>
void swap(int *a , int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int main()
{

	int n , i , j ,q;
	int time;
	scanf("%d",&n);
	int at[n], bt[n] , t[n] , rt[n] ;
	
	for(i = 0; i < n ; i++) {
		scanf("%d%d",&at[i],&bt[i]);
		rt[i] = bt[i];
	}	
	scanf("%d",&q);              // time quantum
	i = 0 , time  = 0;
	int remain = n;
	while(remain > 0) {
		if(rt[i] <= q && rt[i] > 0) {
			time +=rt[i];
			rt[i] = 0;
			remain--;
			printf("Process %d , wait time = %d ,turnaround time = %d\n" , i , time - at[i] -bt[i], time - at[i]);
		}
		else if(rt[i] > 0) {
			time +=q;
			rt[i] -= q;			
		}
		if(i == n-1) 
			i = 0;
		else if(at[i+1] <= time) i += 1;
		
	}
	
	return 0;
}
