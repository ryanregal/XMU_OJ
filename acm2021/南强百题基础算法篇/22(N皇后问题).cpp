#include <iostream>
#include <vector>
using namespace std;
int N;//����ʺ�ĸ���
vector <int> res;
//res�洢�ʺ��һ���

void dfs(int n) {
	if (n==N)//n�������
	{
		for (auto x : res)cout << x;
		cout << endl;
		return;
	}
	//�ٶ�ǰ��Ļʺ�ȫ���ںã����ڰڵ�n��
	for (int i=1;i<=N;i++)
	{
		int k;
		for (k=0;k<n;k++)
		{
			if ((res[k]==i)||abs(res[k]-i)==abs(n-k))//ͬ�л�Խ���
			{
				break;
			}
		}
		if (k==n)
		{
			res[n] = i;
			dfs(n + 1);
		}
	}
}

int main() {
	cin >> N;
	res.resize(N);
	dfs(0);
	return 0;
}
