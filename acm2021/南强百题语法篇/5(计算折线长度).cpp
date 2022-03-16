#include <stdio.h>
#include <math.h>

int main()
{
	int x1, y1, x2, y2, t, n;
	double r;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d%d", &x1, &y1, & x2, &y2);
		if (x1 + y1 > x2 + y2) {
			t = x1, x1 = x2, x2 = t;
			t = y1, y1 = y2, y2 = t;
		}
		r = 0;
		while (1) {
			if (x1 == x2 && y1 == y2) {
				break;
			}
			if (y1 == 0) {
				r += sqrt(x1 * x1 + (x1 + 1) * (x1 + 1));
				y1 = x1 + 1;
				x1 = 0;
			}
			else {
				do {
					r += sqrt(2);
					x1++, y1--;
					if (y1 == 0) {
						break;
					}
				} while (x1 != x2 && y1 != y2);
			}
		}
		printf("%.3lf\n", r);
	}
	return 0;
}
