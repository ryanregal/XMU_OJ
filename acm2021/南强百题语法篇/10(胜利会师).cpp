#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		float u, v, w, l;
		cin >> u >> v >> w >> l;
		cout << setiosflags(ios::fixed);//固定小数位数
		cout << setprecision(3) << w * l / (u + v) << endl;//输出三位小数
	}
	return 0;
}
