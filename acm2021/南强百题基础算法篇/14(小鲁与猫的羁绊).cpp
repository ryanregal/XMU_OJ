#include <iostream>
using namespace std;

int fn(int x) {
	if (x < 5) return x;
	else return fn(x - 1) + fn(x - 3);
}

int main() {
	int n, m;
	cin >> n;
	while (n--)
	{
		cin >> m;
		cout << fn(m) << endl;
	}
	return 0;
}
