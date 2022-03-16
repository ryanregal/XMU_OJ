#include <stdio.h>

int main() 
{
   int x, y;

   while (scanf("%d",&x)==1) 
   {
      y=x*x;
      printf("%d\n", y);
   }

   return 0;
}
