#include<stdio.h>
int main()
{
	int n , r, i , j , p;
	scanf("%d%d",&r,&p);
	
	int alloc[p][r], max[p][r] , need[p][r] , completed[p] , avail[r];
	for(i = 0 ; i < p; i++ ) completed[i] = 0;
	 printf("\n\tEnter No. of Available Instances\n");
	for(i = 0 ; i < r; i++ ) 	
		scanf("%d",&avail[i]);
	printf("\n\tEnter Maximum No. of instances of resources that a Process need:\n");
	for(i = 0 ; i < p; i++ ) {
		for(j = 0 ; j < r; j++ ) 	
			scanf("%d",&max[i][j]);
	}
	printf("\n\t Enter no. of instances already allocated to process of a resource:\n");
	for(i = 0 ; i < p; i++ ) {
		for(j = 0 ; j < r; j++ ) {
			scanf("%d",&alloc[i][j]);
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	printf("\n\t Safe Sequence is:- \t");
	int count = 0;
	int k = 0;
	while(count < p) {
		int x = count;
		 for(i = 0 ; i < p ; i++ ) {
			k = 0;
			for(j = 0 ; j < r; j++ ) {
				if(avail[j] >= need[i][j]) {
					k++;
				}
			}
			if(k == r && completed[i] == 0) {
				for(j = 0 ; j < r; j++ ) {
					avail[j] += alloc[i][j];			
				}
				printf("process %d\t",i);
				completed[i] = 1;
				count++;
			}
		}

		if(x == count) {
			printf("Stop deadlock possible!\n"); break;
		}
	}
	return 0;
}
