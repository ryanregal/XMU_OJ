#include <algorithm>
#include <cstring>
#include <iostream>
#define For(i,a,b) for (int i=a;i<=b;i++)
using namespace std;
bool p[100],used[100];//p����is������Ĭ�ϳ�ʼ��Ϊfalse
int n, a[100], now;//a������������

void dfs(int deep) {//deep��2��ʼ
	if (deep == n + 1 && p[a[1] + a[n]]) {
		//���������ִ���������n������ͷβԪ�غ�Ϊ����,���
		For(i, 1, n) {
			printf("%d", a[i]);
			if (i != n) printf(" ");
		}
		puts("");
		return;
	}
	//�����������
	//�ݹ��������жϵ�i���������Ƿ�Ϸ���
	//���Ϸ����������ж��Ƿ񵽴�Ŀ�꣨����20�����֣��������ӡ���������ݹ������һ����д��һ�����֡�
	//���ǲ��Ϸ���ѡ����һ�ֿ��ܽ��г��ԡ�
	For(i, 2, n) {
		if (p[i + a[deep - 1]] && !used[i])
		{
			used[i] = true;//��¼�ѱ�������
			a[deep] = i;//����a����ֵ
			dfs(deep + 1);
			used[i] = false;//����ʱҪ��used�����false���Ա������һ����ȵݹ飩
		}
	}
}

int main() {
	//����ж��Ƿ�����������Χ<19+17=36
	p[2] = p[3] = p[5] = p[7] = p[11] = p[13] = p[17] = p[19] = p[23] = p[29] = p[31] = true;
	bool isf = false;//�ж��Ƿ�Ҫ�������
	while (~scanf("%d", &n)) {//-1�Ĳ����ʾȫ��1����λȡ����ȫ��0����Ϊ�٣���������������ж�����Ϊ��0
		a[1] = 1;
		if (isf) puts("");
		isf = true;
		printf("Case %d:\n", ++now);
		memset(used, false, sizeof(used));
		dfs(2);
	}
	return 0;
}

