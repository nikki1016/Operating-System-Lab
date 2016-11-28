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
	int q[fs+1] ;
	q[0] = a[0];
	pf++;		
	for(i = 1; i < fs ; i++) { 			// fill the queue for first time
		f = 0 ;		
		//if(n < i+1 ) break;
		for(j = i-1; j >= 0 ; j--) {            
			if(q[j] == a[i]) {
				f = 1;				
				break;
			}
				
		}
		if(f == 0) {
			q[i]  = a[i] ;
			pf++;
		}
	}
	
	for(i = fs; i < n ; i++) {
		int ind = i;
		f = 0 ;		
		for(j = fs-1; j >= 0 ; j--) {           // check if element exists
			if(q[j] == a[i]) {
				f = 1;
				break;
			}				
		}
		if(f == 0) {
			pf++;			
			int k , fl;
			int max = 0 ,  pos = 0;
			for(j = fs-1; j >= 0 ; j--) {   
				fl = 0;		          // find position 
				for(k = ind + 1; k < n ; k++) {
					
					if(q[j] == a[k]) {
						//cout<<q[j]<<" at "<<k<<endl;
						fl = 1;						
						if(max < k) {
							max = k;
							pos = j;
							//cout<<"max = "<<k<<" q[j] =  "<<q[j]<<endl;
							
						}
						break;
					}
				}
				if(fl == 0) {
					//cout<<"not found\n";
					pos = j; 
					break;
				}				
										
			}
			//cout<<q[pos]<<" replaced with"<<a[i]<<"\n";
			q[pos] = a[i] ;
				
		}
	}		
	cout<<"Total pf = "<<pf<<endl;

	return 0;	
}
