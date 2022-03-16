#include <iostream>
#include <algorithm>

using namespace std;
#define INT_MAX 2147483647
const int N = 1007;

int a[N], m, p;

int main() {
	int n;
	while (cin>>n,n>0)
	{
		m = INT_MAX;
		p = 0;
		for (int i=0;i<n;i++)
		{
			cin >> a[i];
			if (m > a[i]) m = a[i], p = i;//记录最小值和相应下标
		}
		swap(a[0], a[p]);//只需要换一次就可以！
		for (int i=0;i<n;i++)
		{
			if (i < n - 1)
			{
				cout << a[i] << ' ';
			}
			else cout << a[i] << endl;
		}
	}
	return 0;
}

