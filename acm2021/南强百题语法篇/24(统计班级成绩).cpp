#include <stdio.h>
int a[50][5];
double b[5];

int main() {
	int n, m;
	double sumstu, sumcos;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		for (int i=0;i<n;i++)
		{
			sumstu = 0;
			for (int j=0;j<m;j++)
			{
				sumstu += a[i][j];
			}
			if (i == n - 1)	 printf("%.2f\n", sumstu / m);
			else  printf("%.2f ", sumstu / m);
		}
		for (int j=0;j<m;j++)
		{
			sumcos = 0;
			for (int i=0;i<n;i++)
			{
				sumcos += a[i][j];
			}
			b[j] = sumcos / n;
			if (j == m - 1)	 printf("%.2f\n", b[j]);
			else  printf("%.2f ", b[j]);
		}
		int cnt = 0;
		for (int i=0;i<n;i++)
		{
			int flag = 1;
			for (int j=0;j<m;j++)
			{
				if (a[i][j]<b[j])
				{
					flag = 0;
				}
			}
			if (flag==1)
			{
				cnt++;
			}
		}
		printf("%d\n\n", cnt);
	}
	return 0;
}
