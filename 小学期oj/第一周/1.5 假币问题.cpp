#include <cstring>
#include <iostream>
using namespace std;

string Left[3];//天平左边
string Right[3];//天平右边
string result[3];

//isLight为真表示假币为轻，否则表示假设假币为重
bool isFeitCoin(char iCoin, bool isLight) {
	string c;
	c.push_back(iCoin);//char 转换为string
	for (int i = 0; i < 3; i++) {
		string l = Left[i], r = Right[i];
		if (!isLight)
			swap(l, r); //假币为重，再另一边判断
		//判断c是否为假币
		switch (result[i][0]) { //天平右边的情况
			case 'e': //两端平衡
				//find () 函数本质上是一个模板函数，用于在指定范围内查找和目标元素值相等的第一个元素
				//如果没找到，返回一个特别的标志c++中用npos表示，npos是一个常数，表示size_t的最大值
				//两端平衡的天平左右都是真币
				if (l.find(c) != string::npos || r.find(c) != string::npos)
					return false;
				break;
			case 'u'://右端，高的那一端没有找到硬币
				if (r.find(c) == string::npos)
					return false;
				break;
			case 'd'://左端，高的那一端没有找到硬币
				if (l.find(c) == string::npos)
					return false;
				break;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 3; ++i) {
			cin >> Left[i] >> Right[i] >> result[i];
		}
		//枚举所有的银币，是否是假币的所有情况
		for (char iCoin = 'A'; iCoin <= 'L'; iCoin++) {
			if (isFeitCoin(iCoin, true)) {
				cout << iCoin << " is the counterfeit coin and it is light. " << endl;
				break;
			} else if (isFeitCoin(iCoin, false)) {
				cout << iCoin << " is the counterfeit coin and it is heavy. " << endl;
				break;
			}
		}
	}
	return 0;
}

