/*
icebear:分形递归+坐标旋转问题
N级城市的房屋数量为2^(2N)个，四个小块，每个小块的房屋数num为2^(2N-2),长度为sqrt(num)=2^(N-1)
坐标旋转：画图分析，第一个房子坐标(0,0)
N-1级的坐标(x,y)转化为N级后：
	①右下：（x+2^(N-1)，y+2^(N-1)）
	②右上：（x,y+2^(N-1)）
	③左上：（y,x）
	④左下：（-x+2^(N)-1，-y+2^(N-1)-1)
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

ll p[40];//第n级分形图编号总数目
void rec(ll n, ll s, ll& x, ll& y) 
{
	if (n == 1)//递归边界
	{
		if (s == 1)x = 1, y = 1;
		else if (s == 2)x = 1, y = 2;
		else if (s == 4)x = 2, y = 1;
		else x = 2, y = 2;
		return;
	}
	//1<<n: 1左移n位变成2^n
	if (s <= p[n - 1])  {//房子位于左上
		rec(n - 1, s, y, x);
	}
	else if (s <= 2 * p[n - 1]){//房子位于右下
		rec(n - 1, s - p[n - 1], x, y);
		y += (1 << n - 1);
	}
	else if (s <= 3 * p[n - 1]){//房子位于右下
		rec(n - 1, s - 2 * p[n - 1], x, y);
		x += (1 << n - 1);
		y += (1 << n - 1);
	}
	else{//房子位于左下
		rec(n - 1, s - 3 * p[n - 1], y, x);
		x = (1 << n) + 1 - x;
		y = (1 << n - 1) + 1 - y;
	}
}
int main()
{
	p[1] = 4;
	for (int i = 2; i <= 33; i++)p[i] = 4 * p[i - 1]; //初始化
	int t;
	scanf("%d",&t);
	while (t--)
	{
		ll s, e, n, sx, sy, ex, ey;
		scanf("%lld%lld%lld", &n, &s, &e);
		rec(n, s, sx, sy); //分别求出s和e的坐标
		rec(n, e, ex, ey);
		printf("%.0f\n", sqrt((sx - ex) * (sx - ex) + (sy - ey) * (sy - ey)) * 10);//正方形边长为10
	}
	return 0;
}
