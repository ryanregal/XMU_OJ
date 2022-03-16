#include <stdio.h>
#include <algorithm>
#define For(a,b,c) for(register int a=b;a<=c;++a)
using namespace std;
int N, q[110000], M;
int main() {
	scanf("%d", &N);
	For(a, 1, N) scanf("%d", &q[a]);
	scanf("%d", &M);
	sort(q + 1, q + N + 1);
	For(a, 1, N) {
		int k = lower_bound(q + a + 1, q + N + 1, M - q[a]) - q;//在[a+1]与[N+1]之间查找不小于M-q[a]的值
		if (k != N + 1 && q[k] == M - q[a])
		{
			return !printf("%d %d", q[a], M - q[a]);
		}
	}
	printf("No");
	return 0;
}


