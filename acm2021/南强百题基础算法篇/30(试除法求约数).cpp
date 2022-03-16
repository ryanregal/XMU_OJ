#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> get_divisors(int n) {//��Լ��������ֵ����vector��
	vector<int> res;
	for (int i=1;i<=n/i;i++)
	{
		if (n%i==0)
		{
			res.push_back(i);//i�����Լ��
			if (i != n / i)//n/iҲ��Լ��������i���ܵ���n/i��������ظ�������
				res.push_back(n / i);
		}
	}
	sort(res.begin(), res.end());
	return res;
}

int main() {
	int n; cin >> n;//����n
	while (n--)
	{
		int a; cin >> a;
		auto res = get_divisors(a);
		for (auto i : res)cout << i << ' '; 
		cout << endl;
	}
	return 0;
}
