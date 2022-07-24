#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 0x3f3f3f;
int n, t,dp[1010][1010], sum[1010];

int DP(int l, int r){
	if(l == r)
		return 0;
	if(l + 1 == r)
		return dp[l][r] = sum[r] - sum[l-1];
	if(dp[l][r] != inf)
		return dp[l][r];
	else{
		for(int i = l; i < r; ++i)	//	i从L开始，此时是单个石子和一大堆合并完的石子进行合并的情况，不能漏
			dp[l][r] = min(dp[l][r], DP(l, i) + DP(i+1, r) + sum[r] - sum[l-1]);
	}
	return dp[l][r];
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> t;
		sum[i] = sum[i-1] + t;
	}
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			dp[i][j] = inf;
	cout << DP(1, n) << endl;
	return 0;
}

