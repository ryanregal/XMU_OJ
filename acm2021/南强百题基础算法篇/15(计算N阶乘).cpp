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
			res.push_back(1);//���������в���һ������
			for (int i = 2; i <= n; i++)
			{
				for (auto& x : res) x *= i;
				int t = 0;//����t���ڱ����λ�ϼ��Ͻ����������ֺ�Ľ��
				for (int j = res.size() - 1; j >= 0; --j)//��λ�ڸ�λ
				{
					int temp = t + res[j];
					t = temp / 10;
					res[j] = temp % 10;
				}
				//����ǰ��һλ����ȥ�����ֽ��д�������������ֿ��ܲ�ֹһλ
				//����Ҫ��һ��whileѭ��һ�����嵽��ǰ��
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
