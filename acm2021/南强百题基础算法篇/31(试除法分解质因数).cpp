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
	if (n > 1)//n�ǳ�ʣ������
	{
		printf("%d %d\n", n, 1);
	}
	puts("");//puts()�����ǰ��ַ����������Ļ������
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
