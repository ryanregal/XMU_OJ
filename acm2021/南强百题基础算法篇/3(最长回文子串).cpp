#include <cstring>
#include <iostream>
using namespace std;

int main() {
	string s,res;
	cin >> s;
	for (int i=0;i<s.size();i++)
	{
		//�������������iΪ���ĵĻ����ִ�
		int left = i - 1, right = i + 1;
		while (left >= 0 && right < s.size() && s[left] == s[right])
		{
			left--, right++;
		}
		if (res.size()<right-left-1)
		{
			res = s.substr(left + 1, right - left - 1);//��������ִ���right-left-1Ϊ����
		}
		//ż�����������i��i+1Ϊ��������
		left = i, right = i + 1;
		while (left >= 0 && right < s.size() && s[left] == s[right])
		{
			left--, right++;
		}
		if (res.size()<right-left-1)
		{
			res = s.substr(left + 1, right - left - 1);
		}
	}
	cout << res << endl;
	return 0;
}
