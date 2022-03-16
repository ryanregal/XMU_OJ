#include <stdio.h>
int main()
{
	int x;
	while (scanf("%d",&x)!=EOF)
	{
		if((x%4==0 && x%100!=0)|| x%400==0)
		{
			printf("Leap year\n");
		}
		else
		{
			printf("Not leap year\n");
		}
	}
	return 0;
}
