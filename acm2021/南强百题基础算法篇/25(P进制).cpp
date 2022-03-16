#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1007;//P�������Nλ
char a[N], P[36];//P����ת�������P�����ַ�ӳ���
inline char f(int n) { return P[n % 36];}
int main() {
	for (int i=0;i<36;i++)
	{
		P[i] = (i < 10) ? char(i + '0') : char(i - 10 + 'A');
	}
	int n, p;
	while (cin>>n>>p)
	{
		int minus = 0;
		if (n<0)
		{
			minus = -1, n = -1 * n;
		}
		int k = 0;
		while (n)
		{
			a[k] = f(n % p);
			k++; 
			n /= p;
		}
		if (minus < 0) cout << "-";
		while (--k >= 0) cout << a[k];
		cout << endl;
	}
	return 0;
}
