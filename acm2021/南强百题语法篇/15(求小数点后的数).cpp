#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		double a;
		int t;
		cin >> a >> t;
		while (t--) {//小数点后几位就乘几次10,得到的数字%10
			a *= 10.0;
		}
		cout << int(a) % 10 << endl;
	}
	return 0;
}

