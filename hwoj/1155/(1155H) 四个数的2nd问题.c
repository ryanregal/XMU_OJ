#include <stdio.h>
		
int main() 
{
    int a[5];
    int temp,i,j;
     
    while (scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3])!=EOF) 
    {
    	for(j=0;j<4;j++)
    	{
			for(i=j+1;i<4;i++)
			{
				if(a[i]>a[j])
				{
					temp=a[j];
					a[j]=a[i];
					a[i]=temp;	
				}
			}
		}
		
		int flag=1;
		for(i=1;i<4;i++)
		{
			if(a[i]!=a[0])
			{
				printf("%d\n",a[i]);
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			printf("%d\n",a[1]);  
		}
	}
	return 0;
}
