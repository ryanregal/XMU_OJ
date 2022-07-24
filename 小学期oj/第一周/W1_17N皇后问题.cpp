#include <iostream>
using namespace std;

// N�ʺ�����
// �ݹ飺ǰn-1�зź��˻ʺ󣬿��ǵ�n�еĻʺ���ڵڼ���
// ͬ�в����������ʺ�б�Խ���Ҳ�����лʺ�

#include <vector>
#include <cmath>

vector<int> res; // ��־��i���±꣩�еĻʺ���ڵ�j�������ֵ����
int N;           // N�ʺ�

void dfs(int n) {
	if (n == N) {
		for (auto i : res) {
			cout << i + 1;
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < N; i++) { // ȡ0~N�� ��̽�Ƿ���Էŵ�n�еĻʺ�
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
	cin >> N;
	res.resize(N);
	dfs(0);
	return 0;
}