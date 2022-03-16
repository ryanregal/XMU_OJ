#include <stdio.h>
#include <math.h>
# define pi 3.1415926536
int main()
{
	double r,o,fi,x,y,z;
	while (scanf("%lf %lf %lf",&r,&o,&fi)!=EOF)
	{ 
		o=(o/180)*pi;
		fi=(fi/180)*pi;
		x=r*sin(o)*cos(fi);
		y=r*sin(o)*sin(fi);
		z=r*cos(o);
		printf("x = %.10f y = %.10f z = %.10f\n",x,y,z);
	}
	return 0;
}
