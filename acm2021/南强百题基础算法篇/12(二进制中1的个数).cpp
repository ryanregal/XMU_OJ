#include <iostream>
using namespace std;

inline int lowbit(int& x) {
	return x & -x;//x的二进制的最后一个1所构成的整数
	//x & -x == x & (~x + 1)
}

int main() {
	int n, x;
	cin >> n;
	while (n--)
	{
		cin >> x;
		int res = 0;
		while (x)
		{
			x -= lowbit(x);
			res++;
		}
		cout << res << " ";
	}
	return 0;
}
