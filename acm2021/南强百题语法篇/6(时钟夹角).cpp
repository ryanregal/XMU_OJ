#include <stdio.h>
#include <math.h>

int main()
{
	int t, h0, m0, s0, x0;
	double h, m, s, n,x;//用double定义时、分、秒
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &h0, &m0, &s0);
		h = h0, m = m0, s = s0;
		double c = s / 60.0;
		m += c;
		double d = m / 60.0;
		h += d;
		if (h >= 12) h -= 12;
		m *= 6, h *= 30;// 60min/12h为360°
		n = fabs(h - m);
		if (n > 180) x = 360 - n;
		else x =n;
		x0=(int)(x);
		printf("%d\n", x0);
	}
	return 0;
}
