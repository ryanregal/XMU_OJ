#include <stdio.h>
#include <math.h>
#include <string.h> 

int main()
{
	int x;
	while (scanf("%d", &x) != EOF)
	{
		int k = sqrt(x);
		printf("%d\n", k);
	}
}
