#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int p, e, i, d, caseNumber = 0;
	while (cin >> p >> e >> i >> d && p != -1) {
		++caseNumber;
		int k;
		for (k = d + 1; (k - p) % 23; k++);
		for (; (k - e) % 28; k += 23);
		for (; (k - i) % 33; k += 23 * 28);
		cout << "Case " << caseNumber << ": the next triple peak occurs in " << k - d << " days." << endl;
	}
	return 0;
}