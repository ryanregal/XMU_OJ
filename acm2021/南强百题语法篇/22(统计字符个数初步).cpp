#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int charcounts[6];
inline int f(char c) {
	if (c == 'a') return 1;
	if (c == 'e') return 2;
	if (c == 'i') return 3;
	if (c == 'o') return 4;
	if (c == 'u') return 5;
	return 0;
}

int main() {
	int n,t;
	cin >> n;
	t = n;
	cin.get();//去掉换行符
	string vowels = "aeiou";
	while(t--){
		for (int i=0;i<6;i++)
		{
			charcounts[i] = 0;
		}
		string str;
		getline(cin, str);
		//字符串要全部变成小写！
		transform(str.begin(), str.end(), str.begin(),::tolower);
		for (int i = 0; i < str.size(); i++)
		{
			charcounts[f(str[i])]++;
		}
		for (int i = 1; i < 6; i++)
		{
			cout << vowels[i-1] << ":" << charcounts[i] << endl;
		}
		if (t > 0) cout << endl;
	}
	return 0;
}
