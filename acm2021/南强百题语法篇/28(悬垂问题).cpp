#include <iostream>
using namespace std;
int main() {
	double x;
	while (cin >> x, x = double(x * 100) * 1.00 / 100.00, x != 0) {
		int i;
		double res = 0.00;
		for (i = 1; res < x; i++)
		{
			res += 1.00 / (2.00 * i);
		}
		if (i == 2) cout << "1 block" << endl;
		else cout << i - 1 << " blocks" << endl;
	}
}
