#include <stdio.h>

int N;
//�ݹ鷨��
int stairs(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else if(n==3) return 4;
	else return stairs(n - 1) + stairs(n - 2)+stairs(n-3);
}
int main() {
	while (scanf("%d",&N)!=EOF)
	{
		printf("%d\n", stairs(N));//���õݹ麯��
	}
	return 0;
}
