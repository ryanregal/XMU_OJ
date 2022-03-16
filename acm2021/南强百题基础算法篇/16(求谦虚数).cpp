#include <iostream>
#include <cstring>
using namespace std;
int a[2001];

bool is_humber(int x) {
	int res = x;
	while (res % 2 == 0) res/= 2;
	while (res % 3 == 0) res/= 3;
	while (res % 5 == 0) res/= 5;
	while (res % 7 == 0) res/= 7;
	return (res == 1);
}

int main() {
	int k = 1, q;
	for (int i = 1;k<=2000;i++)
	{
		if (is_humber(i)) {
			a[k] = i;
			k++;
		}
	}

	cin >> q;
	while (q--)
	{
		int idx;
		cin >> idx;
		cout << a[idx] << endl;
	}
	return 0;
}

