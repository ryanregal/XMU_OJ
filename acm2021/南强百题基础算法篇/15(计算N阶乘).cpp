#include <iostream>
#include <vector>
using namespace std;
vector<int> res;

int main() {
	int n;
	while (cin>>n)
	{
		if (n == 1) cout << "1" << endl;
		else {
			res.push_back(1);//先向向量中插入一个数字
			for (int i = 2; i <= n; i++)
			{
				for (auto& x : res) x *= i;
				int t = 0;//变量t用于保存该位上加上进上来的数字后的结果
				for (int j = res.size() - 1; j >= 0; --j)//个位在高位
				{
					int temp = t + res[j];
					t = temp / 10;
					res[j] = temp % 10;
				}
				//对最前面一位进上去的数字进行处理，由于这个数字可能不止一位
				//所以要用一个while循环一步步插到最前面
				while (t) {
					res.insert(res.begin(), t % 10);
					t /= 10;
				}
			}
			for (auto x : res)cout << x;
			cout << endl;
		}
		res.clear();
	}
	return 0;
}
