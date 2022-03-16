#include <stdio.h>
#include <math.h>
int main()
{
	int x, flag;
	int a[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	while (scanf("%d", &x) != EOF)
	{
		flag=0;
		if (x!=0&&(( x % 4 == 0 && x % 100 != 0) || x % 400 == 0)) {
			for (int j = 1; j < 13; j++) {
				if (flag == 1) {
					break;
				}
				for (int z = 1; z <= a[j - 1]; z++) {
					int ans = x + j * 31 + z;
					int m = floor(sqrt(ans) + 0.5);
					if (m*m==ans) {
						printf("%d %d %d\n", x, j, z);
						flag = 1;
						break;
					}
				}
			}
			if (flag == 0) {
				printf("no leap day\n");
			}
		}
		else {
			printf("no leap day\n");
		}
	}
	return 0;
}
