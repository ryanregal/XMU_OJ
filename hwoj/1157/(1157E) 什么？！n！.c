#include <stdio.h>
int main()
{
	unsigned int x;
	int i,temp=0,j,y;
	while (scanf("%d",&x)!=EOF)
	{
		int num[6]={0,0,0,0,0,1};
		int a=5;
		
		if(x==1)
		{
			printf("000001\n"); 
		}
		else
		{
			for(i=2;i<=x;i++)
			{
				if(num[a]==0)
				{
					a=a-1;
				}
				
				for(int j=a;j>=0;j--)
				{
					y=num[j]*i+temp;
					num[j]=y%10;
					temp=y/10;
				}
				temp=0;
			}
			
			for (int m=0;m<6;m++)
			{
				printf("%d",num[m]);
			}
			printf("\n");
		}
	}
	return 0;
}
