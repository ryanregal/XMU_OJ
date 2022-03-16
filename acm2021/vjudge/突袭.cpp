/*
icebear:平面最近点对问题
将所有点按x坐标排序，从中间分为两部分，最小距离只会有3种情况：
① 在左边部分
② 在右边部分
③ 跨越了中点
分治求解
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int inf = 10e8;
const int N = 100010;
struct Point{
	double x, y;
	bool flag;
}point[2 * N];//存放station和agent数据，其中flag来区别类别 
int tmp[2 * N];//用来记录以mid为中点，2d为宽度的点的下标  

//根据x进行升排序
bool cmpx(Point a, Point b) {
	return a.x < b.x;
}
//根据y进行升排序
bool cmpy(int a, int b) {
	return point[a].y < point[b].y;
}

double dis(Point a, Point b) {
	if (a.flag == b.flag)	return inf;//距离无穷大
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double closest_pair(int l, int r) {
	if (l == r)	return inf;
	if (l + 1 == r)	return dis(point[l], point[r]);//只有两个点的情况
	int mid = l + (r - l) / 2;
	//求左右区间的点对的最小距离
	double distance = min(closest_pair(l, mid), closest_pair(mid + 1, r));
	//求跨越中点的点对的最小距离
	int cnt = 0;
	for (int i = l; i <= r; i++) {
		//点对间距离<distance，如果点对跨越了mid，那么点对到mid的距离也一定要<distance
		if (abs(point[mid].x - point[i].x) <= distance) {
			tmp[cnt++] = i;
		}
	}
	sort(tmp, tmp + cnt, cmpy);
	//冒泡排序法
	for (int i = 0; i < cnt; i++)
		for (int j = i + 1; j < cnt &&  (point[tmp[j]].y - point[tmp[i]].y) < distance; j++) {
			double newdis = dis(point[tmp[i]], point[tmp[j]]);
			if (newdis < distance)	distance = newdis;
		}
	return distance;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &point[i].x, &point[i].y);
			point[i].flag = true;//true代表读入的是站点
		}
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &point[i + n].x, &point[i + n].y);
			point[i + n].flag = false;//false代表读入的是特工
		}
		sort(point, point + 2 * n, cmpx);
		printf("%.3f\n", closest_pair(0, 2 * n - 1));//从（0,2n-1）开始进行分治
	}
	return 0;
}
