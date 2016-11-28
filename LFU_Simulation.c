// handle fs > n case!
#include<stdio.h>
#include<iostream>
using namespace std;
int main() 
{
	int n , i , j , pf , fs , f , cnt , pos;
	pf =0;
	cin>>n;
	int a[n+1];
	for(i = 0 ; i < n ; i++) 
		cin>>a[i];
	cin>>fs;
	int q[fs+1] , time[fs+1];
	q[0] = a[0];
	pf++;	
	cnt = 0;
	time[0] = cnt++ ;  
	for(i = 1; i < fs ; i++) { 			// fill the queue for first time
		f = 0 ;		
		//if(n < i+1 ) break;
		for(j = i-1; j >= 0 ; j--) {            
			if(q[j] == a[i]) {
				f = 1;
				time[j] = cnt++ ;				
				break;
			}
				
		}
		if(f == 0) {
			q[i]  = a[i] ;
			time[i] = cnt++;
			pf++;
		}
	}
	
	for(i = fs; i < n ; i++) {
		f = 0 ;		
		for(j = fs-1; j >= 0 ; j--) {           // check if element exists
			if(q[j] == a[i]) {
				f = 1;
				time[j] = cnt++ ;				
				break;
			}				
		}
		if(f == 0) {
			pf++;			
		
			int min = time[0]; pos = 0;
			for(j = fs-1; j >= 0 ; j--) {             // find position of oldest / lru element in queue
				if(time[j] < min) {
					min = time[j];
					pos = j;
				}							
			}
			q[pos] = a[i] ;
			time[pos] = cnt++;		
		}
	}		

	cout<<"Total pf = "<<pf<<endl;

	return 0;	
}
