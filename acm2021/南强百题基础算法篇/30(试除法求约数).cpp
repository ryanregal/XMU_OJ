#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> get_divisors(int n) {//求约数，返回值存在vector中
	vector<int> res;
	for (int i=1;i<=n/i;i++)
	{
		if (n%i==0)
		{
			res.push_back(i);//i如果是约数
			if (i != n / i)//n/i也是约数，但是i不能等于n/i，否则会重复加两次
				res.push_back(n / i);
		}
	}
	sort(res.begin(), res.end());
	return res;
}

int main() {
	int n; cin >> n;//读入n
	while (n--)
	{
		int a; cin >> a;
		auto res = get_divisors(a);
		for (auto i : res)cout << i << ' '; 
		cout << endl;
	}
	return 0;
}
