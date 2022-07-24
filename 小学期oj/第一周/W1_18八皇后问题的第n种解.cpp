#include <iostream>
using namespace std;

// �˻ʺ�����
// �ݹ飺ǰn-1�зź��˻ʺ󣬿��ǵ�n�еĻʺ���ڵڼ���
// ͬ�в����������ʺ�б�Խ���Ҳ�����лʺ�

#include <vector>
#include <cmath>

int resAll[92][8]; // ��־��i���±꣩���Ϊһ��8int������
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
	for (int i = 1; i <= 8; i++) { // ȡ1~8�� ��̽�Ƿ���Էŵ�n�еĻʺ�
		// ��ǰn-1����û����i��ͬ��ͬ�У���Խ�����Ԫ����ͬ��
		int k;
		for (k = 0; k < n; k++) {
			if (res[k] == i || // ͬ��
				abs(i - res[k]) == abs(n - k)) { // �Խ���
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