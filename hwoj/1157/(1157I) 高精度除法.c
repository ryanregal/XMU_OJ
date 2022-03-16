#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> 

char s[10000];
int len,lenb;
long long int d,point;

int main()
{
	while (scanf("%s %d %d",s,&d,&point)!=EOF)
	{
		long long int sum=0;
        long long int yu=0;
		int a[10000]={0};
		int b[10000]={0};
		
		len=strlen(s);           
	
		for(int i=0;i<=len-1;i++)
		{
			a[i+1]=s[i]-'0';
		}
		
		for(int j=1;j<=len;j++)
		{
			b[j]=(yu*10+a[j])/d;
			yu=(yu*10+a[j])%d;
		}
		
		int lenb=1;
		
		while(b[lenb]==0&&lenb<len)
		{
			lenb++;
		}
			
		for(int j=lenb;j<=len;j++)
		{
			sum+=b[j]*pow(10,(len-j));
		}
		
			if(point==0)
			{
				int temp=0;
				temp=yu*10/d;
				if(temp>=5)
				{
					printf("%d\n",sum+1);  
				}
				else
				{
					printf("%d\n",sum);  
				}
			}
			
			else
			{
				int temp=0;
				int c[200]={0};
				
				for(int k=0;k<=point;k++)
				{
					yu=yu*10;
					temp=yu/d;
					yu=yu%d;
					c[k]=temp;
				}
				
				if(c[point]>=5)
				{
					c[point-1]+=1;
				}
				
				for(int k=point;k>0;k--)
				{
					if(c[k]>=10)
					{
						c[k-1]++;
						c[k]=0;
					}
				}
				
				if(c[0]>=10)
				{
					sum++;
					c[0]=0;
				}
				
				printf("%d.",sum);
				for(int k=0;k<point;k++)
				{
					printf("%d",c[k]);
				}
				printf("\n");
			}
	}
	return 0;
}
