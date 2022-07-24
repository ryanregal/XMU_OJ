#include<iostream>
#include<algorithm>
using namespace std;

int p[1000010];

int binary(int l, int r,int target) {
	while (l < r) {
		int  mid = (l + r) >> 1;
		if (p[mid]>=target)r = mid;
		else l = mid + 1;

		//cout << l << "   " << r << endl;
	}
	if (p[l] == target)return l;
	else return -1;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cout << binary(0, n - 1, x) << endl;
	}
	return 0;
}