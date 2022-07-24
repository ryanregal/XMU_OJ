#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200010;
typedef long long ll;
struct MyStruct
{
	int s, e, d;
}seqs[N];
int n;

ll getsum(int x) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (seqs[i].s <= x) {
			res += (min(seqs[i].e, x) - seqs[i].s) / seqs[i].d + 1;
		}
	}
	return res;
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		int l = 0, r = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int s, e, d;
			cin >> s >> e >> d;
			seqs[i] = { s,e,d };
			r = max(r, e);
		}
		while (l < r) {
			int mid = (l + r) >> 1;
			if (getsum(mid)%2)r = mid;
			else l = mid + 1;
		}
		auto sum = getsum(r) - getsum(r - 1);
		if (sum % 2) cout << r<<" " << sum << endl;
		else puts("There's no weakness.");
	}
	return 0;
}