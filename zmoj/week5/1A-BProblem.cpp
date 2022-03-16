#include <stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long int a, b,c;
		scanf("%ld%ld", &a, &b);
		c = a * b;
		printf("%ld\n",c);
	}
	return 0;
}
