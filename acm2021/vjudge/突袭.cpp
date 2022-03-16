/*
icebear:ƽ������������
�����е㰴x�������򣬴��м��Ϊ�����֣���С����ֻ����3�������
�� ����߲���
�� ���ұ߲���
�� ��Խ���е�
�������
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
}point[2 * N];//���station��agent���ݣ�����flag��������� 
int tmp[2 * N];//������¼��midΪ�е㣬2dΪ��ȵĵ���±�  

//����x����������
bool cmpx(Point a, Point b) {
	return a.x < b.x;
}
//����y����������
bool cmpy(int a, int b) {
	return point[a].y < point[b].y;
}

double dis(Point a, Point b) {
	if (a.flag == b.flag)	return inf;//���������
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double closest_pair(int l, int r) {
	if (l == r)	return inf;
	if (l + 1 == r)	return dis(point[l], point[r]);//ֻ������������
	int mid = l + (r - l) / 2;
	//����������ĵ�Ե���С����
	double distance = min(closest_pair(l, mid), closest_pair(mid + 1, r));
	//���Խ�е�ĵ�Ե���С����
	int cnt = 0;
	for (int i = l; i <= r; i++) {
		//��Լ����<distance�������Կ�Խ��mid����ô��Ե�mid�ľ���Ҳһ��Ҫ<distance
		if (abs(point[mid].x - point[i].x) <= distance) {
			tmp[cnt++] = i;
		}
	}
	sort(tmp, tmp + cnt, cmpy);
	//ð������
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
			point[i].flag = true;//true����������վ��
		}
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &point[i + n].x, &point[i + n].y);
			point[i + n].flag = false;//false�����������ع�
		}
		sort(point, point + 2 * n, cmpx);
		printf("%.3f\n", closest_pair(0, 2 * n - 1));//�ӣ�0,2n-1����ʼ���з���
	}
	return 0;
}
