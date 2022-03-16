#include <stdio.h>
#include <string.h>

int main() {
	char num[31];
	while (scanf("%s", num), * num != '#') {
		int count = 0;
		int cnt = strlen(num);
		for (int i=0;i<cnt-1;i++)
		{
			if (num[i] == '1') count ++;
			printf("%c", num[i]);
		}
		if (num[cnt-1] == 'e') {
			if ((count + 2) % 2 == 0) printf("0\n");
			else printf("1\n");
		}
		else if (num[cnt-1] == 'o') {
			if ((count + 2) % 2 == 0) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}
