#include <stdio.h>
//e.g 12321 1221 1234

int main()
{
	int x;
	while(scanf("%d", &x)!=EOF){
		 if (x < 0 || (x % 10 == 0 && x != 0)) {
            printf("false\n");
            continue;
        }
        int rever= 0;
        while (x > rever) {
            rever = rever * 10 + x % 10;
            x /= 10;
        }
        if(x == rever|| x == rever/ 10){
        	printf("true\n");
        	continue;
		}
		else printf("false\n");
	}
	return 0;
}
