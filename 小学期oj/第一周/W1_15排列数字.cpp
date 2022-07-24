#include <iostream>
using namespace std;

const int N = 10;
int n;
int res[N];			// ��¼�߹���
bool isUsed[N];		// ��¼�Ƿ��ù� ��ֹ�ظ�

void dfs(int u) {
	if (u == n) {
		for (int i = 0; i < n; i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++) {
		if (isUsed[i] == false) { // ûʹ�ù�
			res[u] = i;			  // ������
			isUsed[i] = true;
			dfs(u + 1);
			isUsed[i] = false;	  // �ָ��ֳ�
		}
	}
}

int main() {
	
	cin >> n;
	dfs(0);

	return 0;
}