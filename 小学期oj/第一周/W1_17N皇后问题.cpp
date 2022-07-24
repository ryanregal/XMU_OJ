#include <iostream>
using namespace std;

// N皇后问题
// 递归：前n-1行放好了皇后，考虑第n行的皇后放在第几列
// 同列不能有其他皇后，斜对角线也不能有皇后

#include <vector>
#include <cmath>

vector<int> res; // 标志第i（下标）行的皇后放在第j（数组的值）列
int N;           // N皇后

void dfs(int n) {
	if (n == N) {
		for (auto i : res) {
			cout << i + 1;
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < N; i++) { // 取0~N列 试探是否可以放第n行的皇后
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
	cin >> N;
	res.resize(N);
	dfs(0);
	return 0;
}