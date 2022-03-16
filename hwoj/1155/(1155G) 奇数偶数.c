#include <stdio.h>
int main() 
{
   int x,y;
   
   while (scanf("%d",&x)!=EOF) 
   {
	  if(x%2!=0)
	  {
	  	printf("Odd\n");
	  }
	  else 
	  {
	 	printf("Even\n");
	  }
	}

   return 0;
}
