#include <iostream>
#include <vector>
using namespace std;

int main() {
	int target, n, x;
	vector <int> a;
	cin >> target >> n;
	for (int i=0;i<n;i++)
	{
		cin >> x;
		a.push_back(x);
	}
	//双指针算法！简化计算~
	for (int i=0,j=n-1;i<=j;i++)
	{
		while (j > i && a[i] + a[j] > target)j--;
		if (a[i]+a[j]==target)
		{
			cout << i << " " << j << endl;
			break;
		}
	}
	return 0;
}
