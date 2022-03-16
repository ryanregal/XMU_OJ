#include <stdio.h>
#include <string.h>
#include <math.h>

int i, j, t, n, m, p, k, u, v, z, y, x;
long double a, b, l, r;

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main()
{
	while(scanf("%d%d", &p, &n)!=EOF){
		a = 0; b = 27110000.00;
		for (k = 1; k <= n; k++)
		{
			m = (int)sqrt(k * k / p) + 1;
			t = gcd(k, m);
			l = (double)k / m;
			if (l <= sqrt(p) && l > a)
			{
				a = l;
				x = k / t;
				y = m / t;
			}
			t = gcd(k, m - 1);
			r = (double)k / (m - 1);
			if (r >= sqrt(p) && r < b)
			{
				b = r;
				u = k / t;
				v = (m - 1) / t;
			}
		}
		printf("%d/%d %d/%d\n", x, y, u, v);
	}
	return 0;
}
