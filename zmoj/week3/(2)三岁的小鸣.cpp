#include<stdio.h>
int main()
{
	int a, b, x;
	scanf("%d", &x);
	while (x--)
	{
		scanf("%d%d", &a, &b);
		int sum = a + b;
		printf("%d\n", sum % 100);
	}
	return 0;
}
	
