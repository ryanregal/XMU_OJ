#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	cout<<0; 
	int N,temp,num;
	int a[500]={0};
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>temp;	
	}
	for(int j=0;j<N;j++){
		for(int k=N-1;k>j;k--){
			if(a[j]==a[k]*(-1)) num++;
		}
	}
	cout<<num<<endl;
	return 0;
} 
