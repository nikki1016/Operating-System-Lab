// LFU , handle fs > n case!
#include<stdio.h>
#include<iostream>
using namespace std;
int lfu( int *freq , int *time , int n , int fs) {
	int i , j ;
	int pos , min ;
	min = freq[0];
	pos = 0;
	for( i = 0 ; i < fs; i++) {
		if(min < freq[i]) {
			min = freq[i] ;
			pos = i;
		}
		else if(min == freq[i] && time[pos] > time[i] ) {
			pos = i;
		}
	}
	return pos;

}
int main() 
{
	int n , i , j , pf , fs , f , cnt , pos;
	pf = 0;
	cin>>n;
	int a[n+1];
	for(i = 0 ; i < n ; i++) cin>>a[i];
	cin>>fs;
	int q[fs+1] , freq[fs+1] , time[fs+1];
	q[0] = a[0];
	pf = 1;	
	cnt = 0;
	time[0] = cnt++;
	for(i = 0; i < fs ; i++) {
		freq[i] = 0;
	}
	for(i = 1; i < fs ; i++) { 			// fill the queue for first time
		f = 0 ;		
		//if(n < i+1 ) break;
		for(j = i-1; j >= 0 ; j--) {            
			if(q[j] == a[i]) {
				f = 1;
				freq[j]++;
				time[j] = cnt++;
				break;
			}
				
		}
		if(f == 0) {             // insert in empty pos in queue
			q[i]  = a[i] ;
			time[i] = cnt++;
			freq[i] =1;
			pf++;
		}
	}
	
	for(i = fs; i < n ; i++) {
		f = 0 ;		
		for(j = fs-1; j >= 0 ; j--) {           // check if element exists
			if(q[j] == a[i]) {
				f = 1;
				freq[j]++;
				time[j] = cnt++ ;				
				break;
			}				
		}
		if(f == 0) {
			pf++;	
			int pos = lfu(freq, time , n , fs);
			q[pos] = a[i];
			freq[pos] = 1;
			time[pos] = cnt++;		
				
		}
	}		

	cout<<"Total pf = "<<pf<<endl;

	return 0;	
}
