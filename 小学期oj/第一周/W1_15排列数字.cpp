#include <iostream>
using namespace std;

const int N = 10;
int n;
int res[N];			// 记录走过的
bool isUsed[N];		// 记录是否被用过 防止重复

void dfs(int u) {
	if (u == n) {
		for (int i = 0; i < n; i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++) {
		if (isUsed[i] == false) { // 没使用过
			res[u] = i;			  // 加入结果
			isUsed[i] = true;
			dfs(u + 1);
			isUsed[i] = false;	  // 恢复现场
		}
	}
}

int main() {
	
	cin >> n;
	dfs(0);

	return 0;
}