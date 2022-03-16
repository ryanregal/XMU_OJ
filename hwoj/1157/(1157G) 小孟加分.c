#include <stdio.h>
#define max 100.0000000000
#define plus 0.0000000001

int main()
{
	double x;
	while (scanf("%lf",&x)!=EOF)
	{
		if((x+plus)<=max)
		{
			printf("%.10f\n",x+plus);		
		}
		else
		{
			printf("%.10f\n",max);
		}
	}
	return 0;
}
