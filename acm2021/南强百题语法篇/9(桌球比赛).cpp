#include <iostream>
#include <string>
using namespace std;

int main() {
	int m;
	while (cin >> m) {
		int cntR = 0, cntY = 0;
		char c;//¶ÁÈëm¸ö×Ö·û
		while(m--){
			cin >> c;
			if (c == 'R') cntR++;
			else if (c == 'Y') cntY++;
			if (c == 'B') {
				if (cntR == 7)
					cout << "Red" << endl;
				else
					cout << "Yellow" << endl;
			}
			if (c == 'L') {
				if (cntY == 7)
					cout << "Yellow" << endl;
				else
					cout << "Red" << endl;
			}
		}
	}
	return 0;
}
	
