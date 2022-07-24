#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> PII;
const int N = 25;

int n, m;
char g[N][N]; //�洢����ɭ�ֵ���״̬

// �����λ��
int bfs(int sx, int sy) {
	queue<PII> q; // ����
	q.push({ sx,sy }); // ������������
	g[sx][sy] = '#'; // �����õ㣬����������Ϊǽ
	int res = 0; // ��¼�����ĵ�������������������
	// ������������-1��0����0��1����1��0����0��-1�� ��������
	int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
	// �����л���Ԫ��ʱ
	while (q.size()) {
		auto t = q.front(); //��.frontȡ�ö�ͷԪ�أ�pop��û�з���ֵ��
		q.pop(); // ɾ����ͷԪ��
		res++; //��������������

		// ���ĸ���������
		for (int i = 0; i < 4; i++) {
			// �µ�����
			int x = t.first + dx[i], y = t.second + dy[i];
			// ���겻�Ϸ���continue,�����Ǳ߽�,������ǽ
			if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] != '.')
				continue;
			g[x][y] = '#'; // �����õ㣬����Ϊǽ
			q.push({ x,y }); // ���õ�������
		}
	}
	return res; //���ؽ��
}

int main() {
	// ��������m��n���ֱ��ʾx�����y�����ש������
	while (cin >> m >> n, n || m) { //����n,mΪ0��0Ϊֹ
		for (int i = 0; i < n; i++)
			cin >> g[i]; // ����������ͼ
		int x, y;
		// Ѱ����ʼ��
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (g[i][j] == '@') { 
					x = i;
					y = j;
				}
			}
		}
		// ����ʼ�㴫��bfs����
		cout << bfs(x, y) << endl;
	}
	return 0;
}
