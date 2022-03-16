#include <stdlib.h>
#include <stdio.h>

int main(){
	int x,y,ansm,ansh,ans,x1,x2,y1,y2;
	while (scanf("%d%d", &x, &y)!=EOF){
		x=x%100+(x/100)*60, y=y%100+(y/100)*60;
		if(y<x){
			y+=24*60;
		}
		ansm=(y-x)%60;
		ansh=(y-x)/60; 
		printf("The train journey time is %d hours %d minutes.\n",ansh,ansm);
	}
	return 0;
}

