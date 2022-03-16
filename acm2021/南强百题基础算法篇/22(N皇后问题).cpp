#include <iostream>
#include <vector>
using namespace std;
int N;//读入皇后的个数
vector <int> res;
//res存储皇后的一组解

void dfs(int n) {
	if (n==N)//n遍历完毕
	{
		for (auto x : res)cout << x;
		cout << endl;
		return;
	}
	//假定前面的皇后全部摆好，现在摆第n个
	for (int i=1;i<=N;i++)
	{
		int k;
		for (k=0;k<n;k++)
		{
			if ((res[k]==i)||abs(res[k]-i)==abs(n-k))//同列或对角线
			{
				break;
			}
		}
		if (k==n)
		{
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
