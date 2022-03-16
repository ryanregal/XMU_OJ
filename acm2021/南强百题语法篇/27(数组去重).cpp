#include <stdio.h>


int main() {
	int n,size;
	scanf("%d%d", &n, &size);
	int a[n];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i < size ) {
			int flag = 1;
			for (int j = 0; j < i; j++) {
				if (a[j] == a[i]) {
					flag = 0;
					break;
				}
			}
			if (flag == 1) cnt++;
		}
	}
	printf("%d", cnt + n - size);
	return 0;
}
