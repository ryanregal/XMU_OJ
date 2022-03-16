#include <stdio.h>

int main(void)
{
  int n; 
  while (scanf("%d",&n)!=EOF)
  { 
	  for(int i=n;i>0;i--){
	  	for(int k=0;k<(n-i);k++){
	  		printf(" ");
		}
	  	for(int j=0;j<(2*i-1);j++){	  		
	  		printf("*");
		}
		printf("\n");
	  }
	}
  	return 0;
}
