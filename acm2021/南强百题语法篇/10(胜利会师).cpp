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
		cout << setiosflags(ios::fixed);//�̶�С��λ��
		cout << setprecision(3) << w * l / (u + v) << endl;//�����λС��
	}
	return 0;
}
