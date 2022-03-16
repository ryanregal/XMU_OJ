#include <iostream>
#include <algorithm>
using namespace std;
const int N = 7;
int a[N];

int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> a[0];//a[0]´¢´æ×î´óÖµ
		for (int i = 1; i <= 2; i++) {
			cin >> a[i];
			if (a[0] < a[i])swap(a[0], a[i]);
		}
		cout << (a[0] < a[1] + a[2] ? "OK" : "NO") << endl;
	}
	return 0;
}
