#include<stdio.h>
#include<ctype.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char str[50];
		scanf("%s", str);
		if (!(isalpha(str[0]) || str[0] == '_')) {
			printf("Bad\n");
			continue;
		}
		else{
			int flag = 1;
			for (int i=1;i<strlen(str);i++)
			{
				if (!(isalnum(str[i]) || str[i] == '_')) {
					flag = 0;
					break;
				}
			}
			if (flag == 1) printf("Great\n");
			else printf("Bad\n");
		}
	}
	return 0;
}
