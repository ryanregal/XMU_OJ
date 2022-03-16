#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	int N;
	scanf("%d", &N);
	while(N--){
		double s,u,v,f;
		scanf("%lf%lf",&s,&u);
		double c=atan(1.0/s)-atan(1.0/u);
		v=1.0/tan(c);
		f=v*u-s*u-s*v;
		printf("%.0lf\n",f);//double不可以直接用%d输出 
	}
	return 0;
}

