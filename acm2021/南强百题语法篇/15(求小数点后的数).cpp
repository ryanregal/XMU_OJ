#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		double a;
		int t;
		cin >> a >> t;
		while (t--) {//С�����λ�ͳ˼���10,�õ�������%10
			a *= 10.0;
		}
		cout << int(a) % 10 << endl;
	}
	return 0;
}

