#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> PII;
const int N = 25;

int n, m;
char g[N][N]; //存储迷雾森林地形状态

// 传入点位置
int bfs(int sx, int sy) {
	queue<PII> q; // 队列
	q.push({ sx,sy }); // 将点加入队列中
	g[sx][sy] = '#'; // 净化该点，净化完设置为墙
	int res = 0; // 记录遍历的点数，即净化的区域数
	// 方向向量：（-1，0）（0，1）（1，0）（0，-1） 左下右上
	int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
	// 当队列还有元素时
	while (q.size()) {
		auto t = q.front(); //用.front取得队头元素，pop是没有返回值的
		q.pop(); // 删除队头元素
		res++; //净化区域数增加

		// 向四个方向搜索
		for (int i = 0; i < 4; i++) {
			// 新的坐标
			int x = t.first + dx[i], y = t.second + dy[i];
			// 坐标不合法则continue,比如是边界,或者是墙
			if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] != '.')
				continue;
			g[x][y] = '#'; // 净化该点，设置为墙
			q.push({ x,y }); // 将该点加入队列
		}
	}
	return res; //返回结果
}

int main() {
	// 两个整数m和n，分别表示x方向和y方向瓷砖的数量
	while (cin >> m >> n, n || m) { //读到n,m为0，0为止
		for (int i = 0; i < n; i++)
			cin >> g[i]; // 读入整个地图
		int x, y;
		// 寻找起始点
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (g[i][j] == '@') { 
					x = i;
					y = j;
				}
			}
		}
		// 将起始点传入bfs函数
		cout << bfs(x, y) << endl;
	}
	return 0;
}
