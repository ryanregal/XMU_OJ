#include <iostream>
using namespace std;

// 八皇后问题
// 递归：前n-1行放好了皇后，考虑第n行的皇后放在第几列
// 同列不能有其他皇后，斜对角线也不能有皇后

#include <vector>
#include <cmath>

int resAll[92][8]; // 标志第i（下标）组解为一个8int的数组
int res[8] = { 0 };
int cnt = 0;

void dfs(int n) {
	if (n == 8) {
		for (int k = 0; k < 8; k++) {
			resAll[cnt][k] = res[k];
		}
		cnt++;
		return;
	}
	for (int i = 1; i <= 8; i++) { // 取1~8列 试探是否可以放第n行的皇后
		// 看前n-1行有没有与i相同（同列）或对角线上元素相同的
		int k;
		for (k = 0; k < n; k++) {
			if (res[k] == i || // 同列
				abs(i - res[k]) == abs(n - k)) { // 对角线
				break;
			}
		}
		if (k == n) {
			res[n] = i;
			dfs(n + 1);
		}
	}
}

int main() {
	dfs(0);
	int T;
	cin >> T;
	int t;
	while (T--) {
		cin >> t;
		for (int i = 0; i < 8; i++) {
			cout << resAll[t - 1][i];
		}
		cout << endl;
	}
	return 0;
}