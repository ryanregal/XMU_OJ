#include <stdio.h>
int main()
{
 	int a[]={0,0,0,0,0,0,0,0,0,0,0,1,6,11,18,22,45,63,104,102,205,267,610,924,1677,2271,3865,5429};
 	int b;
 	
 	while (scanf("%d",&b)!=EOF){
 		printf("%d\n",a[b-1]);
	}
return 0;
}
