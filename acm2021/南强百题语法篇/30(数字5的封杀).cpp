#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<int> res;
	string str;
	getline(cin, str);
	//��5�����ָ��������ڽ�βҲҪ��һ���ָ�����
	if (str.back() != '5') str += '5';
	string number;
	for (auto c:str)
	{
		if (c != '5') number += c;
		else if (!number.empty()) {//5֮ǰ�����ִ���
			while (number.size() > 1 && number[0] == '0')
			{
				number = number.substr(1);//��ȡnumber[1]����β������ʼ��0
			}
			res.push_back(stoi(number));
			number.clear();
		}
	}
	sort(res.begin(), res.end());
	for (auto s : res) cout << s << ' ';
	cout << endl;
	return 0;
}
