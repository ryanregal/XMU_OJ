#include<stdio.h>
#include <math.h>

int main()
{
	int x;
	while (scanf("%d",&x)!=EOF)
	{
		int j, sum; 
			sum = 1;
			for (j = 2; j <= x/2; j++) {
				if (x % j == 0) {
					sum += j;
				}
			}
			if (sum == x)
			{
				printf("%d, its factors are 1", x);

				for (j = 2; j <= x/2; j++) {
					if (x % j == 0)printf(" %d", j);
				}
				printf("\n");
			}
			else printf("no\n");
	}
	return 0;
}
	
