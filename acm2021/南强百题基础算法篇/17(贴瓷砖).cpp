#include <iostream>
#include <cstring>
using namespace std;
int n;
int wall[31];
int main() {
	memset(wall, 0, sizeof wall);
	wall[0] = 1; wall[2] = 3;
	for (int i=4;i<=30;i+=2)
	{
		wall[i] = 4 * wall[i - 2] - wall[i - 4];//f(n)=3f(n-2)+2f(n-4)+2f(n-6)+бн+2f(0)
	}
	while (cin>>n,n!=-1)
	{
		cout << wall[n] << endl;
	}
	return 0;
}
