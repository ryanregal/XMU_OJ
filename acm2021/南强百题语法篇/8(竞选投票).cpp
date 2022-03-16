#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int n;
	scanf("%d", &n);
	int A[n+1];
	if (n > 0) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
			A[i] = A[i] / 2 + 1;
		}
		qsort(A, n, sizeof(A[0]), cmp);
		n = n / 2 + 1;
		for (int i = 0; i < n; i++) {
			ans += A[i];
		}
		printf("%d", ans);
	}
	return 0;
}
