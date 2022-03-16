#include <algorithm>
#include <stdio.h>
using namespace std;
#define For(a,b,c) for (register int a=b;a<=c;++a)
int N, g[110000], M, t, l, r;
//1 2 3 3 4 4 5
//t 3 

int main() {
	scanf("%d", &N);
	g[0] = -1E9;//极小值 
	g[N + 1] = 1E9;//极大值 
 	For(a, 1, N) scanf("%d", &g[a]);
	scanf("%d", &M);
	while (M--)
	{
		scanf("%d", &t);
		l = lower_bound(g + 1, g + N + 1, t) - g;//大于等于t的数
		r = upper_bound(g + 1, g + N + 1, t) - g;//大于t的数
		if(l<=N) l--;//避免重复 
		
		if (l == N + 1) printf("%d\n", g[N]);
		else if (r == 1) printf("%d\n", g[1]);
		else printf("%d\n", t - g[l] > g[r] - t ? g[r] : g[l]);
	}
	return 0;
}

