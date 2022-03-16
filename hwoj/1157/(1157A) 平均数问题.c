#include <stdio.h>

int main()
{
	int x,y,z;
	double k;
	while (scanf("%d %d %d",&x,&y,&z)!=EOF)
	{
		k=(x+y+z)/3.0;
		printf("%.3lf\n",k);
	}
	return 0;
}
