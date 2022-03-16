/*
icebear:前缀和问题
分析见P24，注意去重
每对Ai,Bi,令D[Ai+1]-1,D[Bi]+1,即可求解
*/

#include <cstdio>
#include <algorithm>
using namespace std;
int N, H, R, cow[100005];
pair<int, int> p[100005];

int main() {
	int a, b;
	//N头奶牛，最高为H，关系R行
	scanf("%d%*d%d%d", &N, &H, &R);
	for (int i = 0; i < R; i++) {
		scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		p[i].first = a;
		p[i].second =b;
	}
	sort(p, p + R);
	for (int i = 0; i < R; i++) {
		//由于一对关系可能被重复输入多次，故这里通过排序去重
		if ( !i || p[i].first != p[i - 1].first || p[i].second != p[i - 1].second )
			cow[p[i].first + 1]--;
		    cow[p[i].second]++;
	}
	for (int i = 1, d = 0; i <= N; i++) {
		printf("%d\n", (d += cow[i]) + H);
	}
	return 0;
}
