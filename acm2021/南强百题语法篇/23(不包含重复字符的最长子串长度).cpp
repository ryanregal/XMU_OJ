#include <cstring>
#include <iostream>
#include <unordered_map>//���ݽṹ����ϣ����
using namespace std;

//�ⷨһ������ö��(12ms,8.3MB)
// ��ϣ��˫ָ��
//ö��������j��ʼ����i�����Ĳ��ظ��ַ�����ѡ�����
int lengthmax(string s) {
	unordered_map<char, int>heap;//��ϣ��
	int res = 0;
	for (int i=0,j=0;i<s.size();i++)
	{
		heap[s[i]]++;//s[i]����ѣ���ӳ����++��O(1)
		while (heap[s[i]] > 1) 
		{
			heap[s[j++]]--;//��ʼָ���ƶ���ֱ���޳�ǰ����ظ��ַ�
		}
		res = max(res, i - j + 1);
	}
	return res;
}

int main() {
	string s;
	cin >> s;
	cout << lengthmax(s) << endl;
	return 0;
}
