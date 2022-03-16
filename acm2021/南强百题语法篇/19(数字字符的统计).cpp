#include<stdio.h>

int main() {
	int m;
	scanf("%d", &m);
	getchar();
	while (m--) {
		char c;
		int count = 0;
		while (c = getchar(), c != '\n') {
			if (c>='0'&&c<='9')
			{
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
