#include <stdio.h>
/*乘积的取余等于取余的乘积*/
int main()
{
    const int c = 1012;
    int a, b;
	long long int outcom;
 
    while(scanf("%d%d", &a, &b )!=EOF){
    	outcom = 1;
	    if(!a && !b){ //a b都为零则停止循环
	        break;
	    }
	    for(int i=0; i<b; i++){
	        outcom = outcom *a % c;
	    }
		printf("%d\n", outcom);
    }
    return 0;
}
