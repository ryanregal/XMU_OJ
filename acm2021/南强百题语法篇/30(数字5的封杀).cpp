#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<int> res;
	string str;
	getline(cin, str);
	//把5当做分隔符处理，在结尾也要补一个分隔符！
	if (str.back() != '5') str += '5';
	string number;
	for (auto c:str)
	{
		if (c != '5') number += c;
		else if (!number.empty()) {//5之前的数字存在
			while (number.size() > 1 && number[0] == '0')
			{
				number = number.substr(1);//截取number[1]到结尾，清除最开始的0
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
