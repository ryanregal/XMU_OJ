//��Сֵ��󻯵����⡣�ȶԸ����Ŵ�С�������������벻�ᳬ�����˵���ͷţ֮��Ĳ�ֵ����СֵΪ0��
//ͨ������ö����Сֵ������󻯡����赱ǰ����СֵΪx��
//����жϳ���С��ֵΪxʱ���Է���Cͷţ��������x������жϣ�
//����Ų��£�˵����ǰ��x̫���ˣ�������x��СȻ���ٽ����жϡ�ֱ�����һ������x�������յĴ𰸡�
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define For(a,b,c) for (register int a=b;a<=c;++a)
using namespace std;
int N, M, tot = 0, g[110000];//N�����䣬Mͷţ
bool judge(int t) {
	//����������������������mid���������Գ���������ͷţ����С���Ϊmidʱ���ܲ��ܷ���mͷţ
	//����false˵���Ų��£����Ե�mid��������������С�������´γ���
	//����true˵���ܷ��£���mid��ֵ�����Գ��ԼӴ�* /
	int k = M, left = 0;
	For(a, 1, N) {
		left += g[a];
		if (t <= left)//�����λ��֮��������ǵ�ǰ���Ե�ֵt, ��˵����λ�õ�ţ����Է�ţ
		              //������֤�����ǵ�t����С��
		{
			k--;//ţ������1
			if (k == 0) return 1;//ţ��������
			left = 0;
		}
	}
	return 0;
}

int main() {
	cin >> N >> M;
	For(a, 1, N) cin >> g[a];
	sort(g + 1, g + 1 + N);
	int l = 1, r = g[N];
	M--, N--;
	For(a, 1, N) g[a] = g[a + 1] - g[a];
	while (l+1 <r)//����ʱ��l+1=mid > r=mid
	{
		int mid = (l + r) / 2;
		if (judge(mid))l = mid;//mid���Գ��ԼӴ󣬼�����߽絽mid
		else r = mid;//mid̫��Ҫ��С
	}
	printf("%d", l);
	return 0;
}
