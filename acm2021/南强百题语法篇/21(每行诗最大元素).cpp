#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		string temp = s;
		sort(temp.begin(), temp.end());
		char maxchar = temp[temp.length() - 1];
		for (auto c:s)
		{
			cout << c;
			if (c == maxchar)cout << "(max)";
		}
		cout << endl;
	}
	return 0;
}
