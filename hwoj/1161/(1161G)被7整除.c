#include <stdio.h>
#include <math.h>
/* 2^n余数：2、4、1、2、4、1、2、4、1、2、4、1、2、4、1、2、4、1、2、4、1……3数一循环
   n^2余数：1、4、2、2、4、1、0、1、4、2、2、4、1、0、1、4、2、2、4、1、0……7数一循环
  2^n-n^2： 1  0 -1  0  0  0  2  3  4  0  2  4  1  4  0  5  2  6  5  3  1……21数一循环（6个为0）
*/
int main()
{
	int N;
	int arr[6] = { 2,4,5,6,10,15 };
		while (scanf("%d", &N) != EOF) {
			int yu = N % 21;
			int ans = N / 21 * 6;
			for (int i = 0; i < 6; i++) {
				if (yu >= arr[i]) {
					ans++;
				}
			}
			printf("%d\n", ans);
		}
	return 0;
}

