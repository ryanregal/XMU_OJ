#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void divide(int n) {
	for (int i=2;i<=n/i;i++)
	{
		if (n%i==0)
		{
			int nums = 0;
			while (n%i==0)
			{
				n/= i;
				nums++;
			}
			printf("%d %d\n", i, nums);
		}
	}
	if (n > 1)//n是除剩的素数
	{
		printf("%d %d\n", n, 1);
	}
	puts("");//puts()函数是把字符串输出到屏幕并换行
}

int main() {
	int n;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		divide(a);
	}
	return 0;
}
