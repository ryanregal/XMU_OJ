#include <iostream>
using namespace std;
const int N = 107;//ǽ�����Ϊ107

int main() {
	int n, a[N];
	while (cin >> n, n > 0)
	{
		int avg = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			avg += a[i];//����ÿ��ǽ�ĸ߶�ʱ˳���ƽ��ֵ����
		}
		avg /= n;
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < avg) {
				res += avg - a[i];//�����ȱ��ש����Ҫ�ƶ��Ĵ���
			}
		}
		cout << res << endl << endl;
	}
	return 0;
}

