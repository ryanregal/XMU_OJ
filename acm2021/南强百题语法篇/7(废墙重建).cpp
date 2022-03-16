#include <iostream>
using namespace std;
const int N = 107;//墙最大宽度为107

int main() {
	int n, a[N];
	while (cin >> n, n > 0)
	{
		int avg = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			avg += a[i];//读入每个墙的高度时顺便把平均值求了
		}
		avg /= n;
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < avg) {
				res += avg - a[i];//算出空缺的砖即需要移动的次数
			}
		}
		cout << res << endl << endl;
	}
	return 0;
}

