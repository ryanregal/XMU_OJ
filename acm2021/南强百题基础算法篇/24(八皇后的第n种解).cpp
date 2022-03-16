#include <cstring>
#include <iostream>
using namespace std;
int queenSpace[92][8];//八皇后的解空间数组，每一行是一种皇后的摆法
int res[8];
int cnt = 0;
void dfs(int n) {
	if (n>7)//当棋盘全部遍历完毕
	{
		for (int k = 0; k < 8; k++) queenSpace[cnt][k] = res[k];
		cnt++;
		return;
	}
	//现在摆第n个皇后
	for (int i=1;i<=8;i++)
	{
		int k;
		for (k=0;k<n;k++)
		{
			if ((res[k]==i)||abs(res[k]-i)==abs(n-k)) break;
		}
		if (n==k)
		{
			res[n] = i;
			dfs(n + 1);
		}
	}
}

int main() {
	int T, n;
	memset(res, 0, sizeof(res));
	cnt = 0;
	dfs(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < 8; i++) cout << queenSpace[n - 1][i];
		cout << endl;
	}
	return 0;
}
