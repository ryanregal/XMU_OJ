#include <iostream>
using namespace std;
int N;
//�ݹ鷨��
int stairs(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else return stairs(n - 1) + stairs(n - 2);
}
int main() {
	int Q;
	while (scanf("%d",&Q)!=EOF)
	{
		while (Q--)
		{
			scanf("%d", &N);
			printf("%d\n", stairs(N));//���õݹ麯��
		}
	}
	return 0;
}
