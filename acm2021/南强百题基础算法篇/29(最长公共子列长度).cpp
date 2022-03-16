#include <iostream>
#include <cstring>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 1007
int maxSlength[N][N];
char s1[1007], s2[1007];
int main() {
	while (scanf("%s%s",s1,s2)!=EOF)
	{
		int len1 = strlen(s1), len2 = strlen(s2);
		for (int i = 0; i <= len1; i++) maxSlength[i][0] = 0;
		for (int i = 0; i <= len2; i++) maxSlength[0][i] = 0;

		for (int i=1;i<=len1;i++)
		{
			for (int j=1;j<=len2;j++)
			{
				if (s1[i - 1] == s2[j - 1]) maxSlength[i][j] = maxSlength[i - 1][j - 1] + 1;
				else maxSlength[i][j] = max(maxSlength[i - 1][j], maxSlength[i][j - 1]);
			}
		}
		cout << maxSlength[len1][len2] << endl;
	}
}
