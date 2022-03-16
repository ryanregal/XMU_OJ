#include <cstring>
#include <iostream>
using namespace std;

int main() {
	string s,res;
	cin >> s;
	for (int i=0;i<s.size();i++)
	{
		//奇数回文情况，i为中心的回文字串
		int left = i - 1, right = i + 1;
		while (left >= 0 && right < s.size() && s[left] == s[right])
		{
			left--, right++;
		}
		if (res.size()<right-left-1)
		{
			res = s.substr(left + 1, right - left - 1);//保留最长的字串，right-left-1为长度
		}
		//偶数回文情况，i与i+1为回文中心
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
