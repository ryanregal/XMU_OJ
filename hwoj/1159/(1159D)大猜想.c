#include <stdio.h>
int main()
{
	int x;
	while (scanf("%d", &x) != EOF){
		int count=0;
		while(x!=1){
			if(x%2==0)
			{
				x=x/2;
				count++;
			}
			else if(x%2!=0)
			{
				x=x*3+1;
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
