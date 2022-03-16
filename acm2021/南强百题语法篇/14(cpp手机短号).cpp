#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		cout << "6" + s.substr(6) << endl;
	}
	return 0;
}

