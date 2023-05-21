#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct window{
	int x1;
	int y1;
	int x2;
	int y2;
	int no;
};

window mywindow[10];

void exchange(int no1,int no2){
	window temp;
	temp.x1=mywindow[no1].x1;
	temp.y1=mywindow[no1].y1;
	temp.x2=mywindow[no1].x2;
	temp.y2=mywindow[no1].y2;
	temp.no=mywindow[no1].no;
	mywindow[no1].x1=mywindow[no2].x1;
	mywindow[no1].x2=mywindow[no2].x2;
	mywindow[no1].y1=mywindow[no2].y1;
	mywindow[no1].y2=mywindow[no2].y2;
	mywindow[no1].no=mywindow[no2].no;
	mywindow[no2].x1=temp.x1;
	mywindow[no2].x2=temp.x2;
	mywindow[no2].y1=temp.y1;
	mywindow[no2].y2=temp.y2;
	mywindow[no2].no=temp.no;
}

int main(){
	int N,M;
	cin>>N>>M;
	//从最下层到最顶层的顺序 
	for(int i=0;i<N;i++){
		cin>>mywindow[i].x1>>mywindow[i].y1>>mywindow[i].x2>>mywindow[i].y2;
		mywindow[i].no=i+1;
	}
	while(M--){
		int x,y,flag=0;
		cin>>x>>y;
		for(int i=N-1;i>=0;i--){
			if(x>=mywindow[i].x1 && x<=mywindow[i].x2 && y>=mywindow[i].y1 && y<=mywindow[i].y2){
				cout<<mywindow[i].no<<endl;
			//	cout<<"当前窗口位置："<<mywindow[i].no<<endl; 
				exchange(i,N-1);
				flag=1;
				break;
			}
		}
		if(flag==0) cout<<"IGNORED"<<endl;
	}
	return 0;
} 							

