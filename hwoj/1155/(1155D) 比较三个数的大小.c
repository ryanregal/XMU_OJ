#include <stdio.h>
int main() 
{
   int x,y,z,max;

   while (scanf("%d %d %d",&x,&y,&z)!=EOF) 
   {
      if(x>=y)
      {
      	max=x;
	  }
      else
      {
      	max=y;
	  }
	  
	  if(z>max)
	  {
	  	max=z;
	  }
	  printf("%d\n",max);
   }
   
   return 0;
}
