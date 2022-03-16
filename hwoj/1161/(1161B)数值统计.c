#include <stdio.h>
#include <math.h>

int main()
{
	float x,n;
	while(scanf("%f",&n)!=EOF)
	{
		int a=0,b=0,c=0;
		if(n==0){
			break;
		}
		for(int i=1;i<=n;i++){
			scanf("%f",&x);
			if(x<0) a++;
			if(x==0) b++;
			if(x>0)c++;
		}
		printf("%d %d %d\n",a,b,c);		
	}
	return 0;
}

