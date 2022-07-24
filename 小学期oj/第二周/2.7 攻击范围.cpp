#include<iostream>
#include<algorithm>
using namespace std;

int p[1000010];


int main() {
	ios::sync_with_stdio(false);
	int n;
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int l = 0, r = n - 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (p[mid] >= x) r = mid;
			else l = mid + 1;
		}
		if (p[l] != x)
			cout << "-1 -1" << endl;
		else {
			cout << l << " ";
			l = 0, r = n - 1;
			while (l < r) {
				int mid = (l + r + 1) >> 1;
				if (p[mid] <= x) l=mid;
				else r=mid-1;
			}
			cout << l << endl;
		}
	}
	return 0;
}