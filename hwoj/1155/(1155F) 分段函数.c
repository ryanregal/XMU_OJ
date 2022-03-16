#include <stdio.h>
int main() 
{
   int x,y;
   
   while (scanf("%d",&x)!=EOF) 
   {
	  if(x>=0&&x<=100)
	  {
	  	y=-100+2*x;
	  	printf("%d\n",y);
	  }
	  else if(x>100&&x<=500)
	  {
	  	y=200;
	  	printf("%d\n",y);
	  }
	  else if(x>500)
	  {
	  	y=1.5*x-650;
	  	printf("%d\n",y);
	  }

   }

   return 0;
}
