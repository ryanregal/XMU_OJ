#include <iostream>
using namespace std;
const int maxN = 1007;
int s[maxN + 1][maxN + 1];
int n;

int solve(int n) {//自下往上求 
	int* dPointer = s[n];//指向d最后一行
	for (int i=n-1;i>=1;i--)
	{
		for (int j=1;j<=i;j++)
		{
			dPointer[j] = s[i][j] + max(dPointer[j], dPointer[j + 1]);//从左往右计算
		}
	}
	return dPointer[1];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)//从n-1往上遍历
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> s[i][j];
		}
	}
	cout << solve(n) << endl;
}
