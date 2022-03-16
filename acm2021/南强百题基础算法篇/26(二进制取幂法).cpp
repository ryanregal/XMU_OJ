//Binary Exponentiation

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int qmi(int a, int k, int p) {//a^k mod p
	int res = 1;
	while (k)
	{
		if (k & 1) {//k������ĩβΪ1
			res = (LL)res * a % p;
		}
		k >>= 1;//����һλ��ǰ�油0
		a = (LL)a * a % p;
	}
	return res;
}

int main() {
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int a, k, p;
		scanf("%d%d%d", &a, &k, &p);
		printf("%d\n", qmi(a, k, p));
	}
	return 0;
}
