/*
icebear:ǰ׺������
������P24��ע��ȥ��
ÿ��Ai,Bi,��D[Ai+1]-1,D[Bi]+1,�������
*/

#include <cstdio>
#include <algorithm>
using namespace std;
int N, H, R, cow[100005];
pair<int, int> p[100005];

int main() {
	int a, b;
	//Nͷ��ţ�����ΪH����ϵR��
	scanf("%d%*d%d%d", &N, &H, &R);
	for (int i = 0; i < R; i++) {
		scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		p[i].first = a;
		p[i].second =b;
	}
	sort(p, p + R);
	for (int i = 0; i < R; i++) {
		//����һ�Թ�ϵ���ܱ��ظ������Σ�������ͨ������ȥ��
		if ( !i || p[i].first != p[i - 1].first || p[i].second != p[i - 1].second )
			cow[p[i].first + 1]--;
		    cow[p[i].second]++;
	}
	for (int i = 1, d = 0; i <= N; i++) {
		printf("%d\n", (d += cow[i]) + H);
	}
	return 0;
}
