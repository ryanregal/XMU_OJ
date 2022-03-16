#include <string>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	getchar();//È¥µô»»ÐÐ·û
	while (n--) {
		string a,b;
		getline(cin, a);
		getline(cin, b);
		int p = a.size() / 2;
		cout << a.substr(0,p)+b +a.substr(p) << endl;
	}
}
