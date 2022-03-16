/*
icebear:���εݹ�+������ת����
N�����еķ�������Ϊ2^(2N)�����ĸ�С�飬ÿ��С��ķ�����numΪ2^(2N-2),����Ϊsqrt(num)=2^(N-1)
������ת����ͼ��������һ����������(0,0)
N-1��������(x,y)ת��ΪN����
	�����£���x+2^(N-1)��y+2^(N-1)��
	�����ϣ���x,y+2^(N-1)��
	�����ϣ���y,x��
	�����£���-x+2^(N)-1��-y+2^(N-1)-1)
*/

#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <bitset>
using namespace std;
typedef long long ll;

ll p[40];//��n������ͼ�������Ŀ
void rec(ll n, ll s, ll& x, ll& y) 
{
	if (n == 1)//�ݹ�߽�
	{
		if (s == 1)x = 1, y = 1;
		else if (s == 2)x = 1, y = 2;
		else if (s == 4)x = 2, y = 1;
		else x = 2, y = 2;
		return;
	}
	//1<<n: 1����nλ���2^n
	if (s <= p[n - 1])  {//����λ������
		rec(n - 1, s, y, x);
	}
	else if (s <= 2 * p[n - 1]){//����λ������
		rec(n - 1, s - p[n - 1], x, y);
		y += (1 << n - 1);
	}
	else if (s <= 3 * p[n - 1]){//����λ������
		rec(n - 1, s - 2 * p[n - 1], x, y);
		x += (1 << n - 1);
		y += (1 << n - 1);
	}
	else{//����λ������
		rec(n - 1, s - 3 * p[n - 1], y, x);
		x = (1 << n) + 1 - x;
		y = (1 << n - 1) + 1 - y;
	}
}
int main()
{
	p[1] = 4;
	for (int i = 2; i <= 33; i++)p[i] = 4 * p[i - 1]; //��ʼ��
	int t;
	scanf("%d",&t);
	while (t--)
	{
		ll s, e, n, sx, sy, ex, ey;
		scanf("%lld%lld%lld", &n, &s, &e);
		rec(n, s, sx, sy); //�ֱ����s��e������
		rec(n, e, ex, ey);
		printf("%.0f\n", sqrt((sx - ex) * (sx - ex) + (sy - ey) * (sy - ey)) * 10);//�����α߳�Ϊ10
	}
	return 0;
}
