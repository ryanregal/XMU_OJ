#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
	long long a, b;
	cin >> setbase(16);
	cout << setiosflags(ios::uppercase) << setbase(16);
	while (cin >> a >> b) {
		long long res = a + b;
		if (res < 0)
			cout << "-" << -(res) << endl;
		else
			cout << res << endl;
	}
	return 0;
}
