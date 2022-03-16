#include <stdio.h>

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	int a[m][n];
	int max = 0, max_m=0, max_n=0;
	for (int i=0;i<m;i++)
	{
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j]>max)
			{
				max = a[i][j];
				max_m = i + 1;
				max_n = j + 1;
			}
		}
	}
	printf("%d %d %d", max_m, max_n, a[max_m - 1][max_n - 1]);
	return 0;
}
