//最小值最大化的问题。先对隔间编号从小到大排序，最大距离不会超过两端的两头牛之间的差值，最小值为0。
//通过二分枚举最小值来求最大化。假设当前的最小值为x。
//如果判断出最小差值为x时可以放下C头牛，就先让x变大再判断；
//如果放不下，说明当前的x太大了，就先让x变小然后再进行判断。直到求出一个最大的x就是最终的答案。
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define For(a,b,c) for (register int a=b;a<=c;++a)
using namespace std;
int N, M, tot = 0, g[110000];//N个隔间，M头牛
bool judge(int t) {
	//函数接受主函数传进来的mid，作用是试出当任意两头牛的最小间距为mid时，能不能放下m头牛
	//返回false说明放不下，尝试的mid大，在主函数中缩小，进行下次尝试
	//返回true说明能放下，但mid的值还可以尝试加大* /
	int k = M, left = 0;
	For(a, 1, N) {
		left += g[a];
		if (t <= left)//如果两位置之差大于我们当前尝试的值t, 就说明该位置的牛舍可以放牛
		              //这样保证了我们的t是最小的
		{
			k--;//牛个数减1
			if (k == 0) return 1;//牛都放完了
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
	while (l+1 <r)//结束时有l+1=mid > r=mid
	{
		int mid = (l + r) / 2;
		if (judge(mid))l = mid;//mid可以尝试加大，即让左边界到mid
		else r = mid;//mid太大，要变小
	}
	printf("%d", l);
	return 0;
}
