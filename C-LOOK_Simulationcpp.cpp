#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int hash[1000000];
int clook(int *a , int n , int start , int end , int *k ) {
	int i , j , stime = 0;	
	int prev = start;
	if(start > end ) {
		for(i = start ; i >= end ;i-- ) {
			if(hash[i] == 1) {
				cout<<i<<" ";
				stime += prev - i ;
				prev = i; (*k)++;
				if(*k == n ) break;
			}
		}
	}
	else {
		for(i = start ; i <= end ;i++ ) {
			if(hash[i] == 1) {
				stime += i - prev ;
				cout<<i<<" ";
				prev = i; (*k)++;
			}
			if(*k == n ) break;
		}
	}
	return stime;
}
int main() 
{
	int n , i , j , f , cnt , pos ,head;
	int stime =0;
	cin>>n;
	int a[n+1];
	int mn , mx;
	cin>>a[0];
	mn = mx = a[0];
	hash[a[0]] = 1;
	for(i = 1 ; i < n ; i++) {
		cin>>a[i];
		if(mn > a[i]) mn = a[i];
	 if(mx < a[i]) mx = a[i];
		hash[a[i]] = 1;

	}
	cin>>head;
	int end , start;
	if( abs(head - mn) > abs(head - mx) )  
		end = mx;
	else end = mn;
	start = head;
	int k = 0; 
	stime+= clook(a , n , start , end , &k);
	if(end == mx) start = mn ;
	else start = mx;
	stime+= clook(a , n , start , end , &k);

	end = head;  // for direction 
	
	cout<<"seek time = "<<stime<<endl;
	
	return 0;
}
