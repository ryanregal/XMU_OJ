#include <stdio.h>
#include <math.h>
#include <string.h> 

int main()
{
	char x[4];
	while (scanf("%s", &x) != EOF)
	{
		int temp = 0;
		int lens = strlen(x);
		for (int i = 0; i < lens; i++) {
			temp += (x[i] - '0') * pow(10, i);
			x[i] = 0;
		}
		printf("%d\n", temp);
	}
	return 0;
}
