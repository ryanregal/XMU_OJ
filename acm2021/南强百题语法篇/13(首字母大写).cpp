#include <iostream>
#include <string>
using namespace std;

int main() {
	string line;
	int i, len;
	char ch;
	while (getline(cin, line))
	{
		len = line.size();
		if (line[0] >= 'a' && line[0] <= 'z') line[0] -= 32;

		//Ë«Ö¸ÕëËã·¨
		for (int i = 0; i < len - 1; i++) {
			if (line[i] == ' ') {
				if (line[i + 1] >= 'a' && line[i + 1] <= 'z') line[i + 1] -= 32;
			}
			else if (line[i + 1] >= 'A' && line[i + 1] <= 'Z') line[i + 1] += 32;
		}
		cout << line << endl;
	}
	return 0;
}
