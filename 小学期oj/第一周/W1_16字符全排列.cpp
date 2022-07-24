#include <iostream>
using namespace std;

#include <string>
#include <algorithm>
#include <vector>

string path;
vector<bool> isUsed;

void dfs(string s, int u) {
	if (u == s.size()) {
		cout << path << endl;
	}

	for (int i = 0; i < s.size(); i++) {
		if (isUsed[i] == false) {
			isUsed[i] = true;
			path[u] = s[i];
			dfs(s, u + 1);
			isUsed[i] = false;
		}
	}
}

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	// 初始化path和isUsed
	path = s;  // path内容不重要，把大小初始化就行
	isUsed = vector<bool>(s.size());
	dfs(s, 0);

	// 或调用方法生成下一个字典序
	while (next_permutation(s.begin(), s.end())) {
		cout << s << endl;
	}

	return 0;
}