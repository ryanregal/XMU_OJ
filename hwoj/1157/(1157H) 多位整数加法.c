#include <stdio.h>
#include <string.h>
//122345 
int main()
{
	char x[101]={'\0'};
	char y[101]={'\0'};
	int i,j,k;
	
	while (scanf("%s %s",&x,&y)!=EOF)
	{
		int num1[101]={0};
		int num2[101]={0};
		int len=strlen(x);
		for(i=0,j=len-1;j>=0;i++,j--)
		{
			num1[i]=x[j]-'0';
		}
		for(i=0,j=strlen(y)-1;j>=0;i++,j--)
		{
			num2[i]=y[j]-'0'; 
		}
	
		for(k=0;k<len;k++)
		{
			num1[k]+=num2[k];
			if(num1[k]>=10)
			{
				num1[k]-=10;
				num1[k+1]++;
			}
		}
		
		int flag=0;//¼ÇÂ¼Î»Êý 
		for(i=len;i>=0;i--)
		{
			if(num1[i]!=0)
			{
				flag=i;
				break;
			}
		}
		
		if(i==-1)
		{
			printf("0\n");
		}
		else
		{
			for(i=flag;i>=0;i--)
			{
				if(i!=0)
				{
					printf("%d",num1[i]);
				}
				else
				{
					printf("%d\n",num1[i]);
				}
			}
		}
	}
	return 0;
}
