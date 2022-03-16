#include <stdio.h>
int main() {
	int t;
	scanf("%d", &t);
	int f[1000];
	while (t--)
	{
		int sum=0;
		int a, b,l,r;
		scanf("%d%d%d%d", &a, &b,&l,&r);
		f[0] = a, f[1] = b;
		for (int i = 2; i <= r; i++) {
			f[i] = f[i - 1]%1000 + f[i -2]%1000;
			f[i] = f[i] % 1000;
		}
		for (int i=l;i<=r;i++)
		{
			sum += f[i];
		}
		sum = sum % 1000;
		printf("%d\n", sum);
	}
	return 0;
}
