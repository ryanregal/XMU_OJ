#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;
//维护两张哈希表，第一张哈希表以s中字符为键，映射至t的字符为值,第二张哈希表以t中字符为键，映射至s的字符为值。
//从左至右遍历两个字符串的字符，不断更新两张哈希表
//如果出现冲突（即当前下标index对应的字符s[index]已经存在映射且不为t[index]或相反)返回false
bool isIsomorphic(string s, string t) {
	unordered_map<char, char>st, ts;
	for (int i=0;i<s.size();i++)
	{
		int a = s[i], b = t[i];
		if (st.count(a) && st[a] != b)return false;
		if (ts.count(b) && ts[b] != a)return false;
		st[a] = b, ts[b] = a;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s, t;
		cin >> s >> t;
		if (isIsomorphic(s, t)) cout << "true" << endl;
		else cout << "false" << endl;
	}
	return 0;
}
