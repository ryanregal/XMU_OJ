#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;
//ά�����Ź�ϣ����һ�Ź�ϣ����s���ַ�Ϊ����ӳ����t���ַ�Ϊֵ,�ڶ��Ź�ϣ����t���ַ�Ϊ����ӳ����s���ַ�Ϊֵ��
//�������ұ��������ַ������ַ������ϸ������Ź�ϣ��
//������ֳ�ͻ������ǰ�±�index��Ӧ���ַ�s[index]�Ѿ�����ӳ���Ҳ�Ϊt[index]���෴)����false
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
