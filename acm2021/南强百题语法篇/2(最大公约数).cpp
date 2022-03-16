#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int r = a % b;
		while (r != 0)
		{
			a = b;
			b = r;
			r = a % b;
		}
		printf("%d", b);
		if(n!=0){
			printf("\n"); 
		}
	}
	return 0;
}
