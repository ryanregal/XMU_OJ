#include <iostream>
using namespace std;

#include <bitset>
#include <vector>

vector<string> res;

void dfs(int n) {
	bitset<16> a(n); // 把n转化为二进制
	bool isFirst = true; // 标志是否为第一位
	for (int i = 15; i >= 0; i--) {
		if (a.test(i)) { // 第i位是1
			if (isFirst == true) {
				isFirst = false;
			}
			else {
				cout << "+";
			}
			if (i == 0) {
				cout << "2(0)";
			}
			else if (i == 1) {
				cout << "2";
			}
			else
			{
				cout << "2(";
				dfs(i);
				cout << ")";
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	dfs(n);
	return 0;
}