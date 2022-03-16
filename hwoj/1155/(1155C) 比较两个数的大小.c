#include <stdio.h>
int main() 
{
   int x, y,f;

   while (scanf("%d %d",&x,&y)!=EOF) 
   {
      if(x>=y)
      {
      	printf("%d\n",x);
	  }
      else
      {
      	printf("%d\n",y);
	  }
   }

   return 0;
}
