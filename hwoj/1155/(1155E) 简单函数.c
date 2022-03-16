#include <stdio.h>
int main() 
{
   int x,y;

   while (scanf("%d",&x)!=EOF) 
   {
   	  y=2000-2*x;
      printf("%d\n",y);
   }

   return 0;
}
