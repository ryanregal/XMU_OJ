#include<stdio.h>
#include <string.h>

int cmp(const void* a, const void* b) {
	int x = *((int*)a);
	int y = *((int*)b);
	if (x % 2 == 0 && y % 2 != 0) return 1;
	else if (x % 2 != 0 && y % 2 == 0) return -1;
	else if (x > y) return 1;
	else if (x < y) return -1;
	else return 0;
}

int main(){
	int n,num[50];
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n;i++) {
			scanf("%d", &num[i]);
		}
		qsort(num, n, sizeof(int), cmp);
		for (int i = 0; i < n; i++) {
			printf("%d", num[i]);
			if (i != n - 1) printf(" ");
		}
		printf("\n");
		memset(num, 50, sizeof(int));
	}
}
