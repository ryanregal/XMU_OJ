#include<stdio.h>
int main()
{
	int n;
	while (scanf("%d",& n) != EOF) {
		int j, k, t, odd = -1, even = n, a[20];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] % 2 != 0) odd++;
			else even--;
		}
		for (int i = 0; i <= odd; i++) {  //����������ߣ�ż�����ұߣ�ÿ�δ�λ�ͽ��� 
			for (j = n-1; j >= even; j--){
				if (a[i] % 2 == 0 && a[j]!= 0){
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
			}
		}
		for (int i = 0; i < odd; i++) {    //ѡ��������� 
			for (j = i + 1; j <= odd; j++) {
				if (a[i] > a[j]) {
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
			}
		}
		for (int i = even; i < n; i++)    //ѡ�������ұ� 
			for (j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
		}
		for (int i = 0; i < n; i++) {
			printf("%d", a[i]);
			if (i != n - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
