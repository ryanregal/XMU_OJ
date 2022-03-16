#include <cstring>
#include <iostream>
#include <unordered_map>//数据结构：哈希集合
using namespace std;

//解法一：暴力枚举(12ms,8.3MB)
// 哈希表、双指针
//枚举所有以j开始，以i结束的不重复字符串，选择最长的
int lengthmax(string s) {
	unordered_map<char, int>heap;//哈希表
	int res = 0;
	for (int i=0,j=0;i<s.size();i++)
	{
		heap[s[i]]++;//s[i]插入堆，且映射项++，O(1)
		while (heap[s[i]] > 1) 
		{
			heap[s[j++]]--;//起始指针移动，直至剔除前面的重复字符
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
