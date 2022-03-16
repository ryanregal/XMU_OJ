#include <stdio.h>
#include <math.h>
int main()
{
	int x,y;
	while (scanf("%d", &x) != EOF){
		y=sqrt(x);
		if(x==y*y){
			printf("y\n");
		} 
		else{
			printf("n\n");
		}
	}
return 0;
}
