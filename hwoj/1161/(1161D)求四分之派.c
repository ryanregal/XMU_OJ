#include <stdio.h>
#include <math.h> 
int main()
{
	double pi=0;
	int i,n,j=1;
	for(i=2,n=1;fabs(1/(double)n)>pow(10,-6);i++,n+=2){
		pi+=pow(-1,i)*j/(double)n;
	}
	printf("%lf",pi);
return 0;
}
 
