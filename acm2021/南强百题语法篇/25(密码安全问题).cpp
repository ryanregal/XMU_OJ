#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	int c;
	scanf("%d", &c);
	while (c--) {
		char str[100];
		scanf("%s", str);
		int judge[4] = { 0,0,0,0 };
		int size = strlen(str);
		if (size < 8 || size>16) {
			printf("NO\n");
			break;
		}
		int flag=1;
		for (int i = 0; i < size; i++) {
			if (islower(str[i])) judge[0] = 1;
			else if (isupper(str[i])) judge[1] = 1;
			else if (isdigit(str[i])) judge[2] = 1;
			else if (str[i] == '~' || str[i] == '!' || str[i] == '@' || str[i] == '#' ||
				str[i] == '$' || str[i] == '%' || str[i] == '^') {
				judge[3] = 1;
			}
			else{
				printf("NO\n");
				flag=0;
				break;
			}
		}
		if(flag){
			if ((judge[0] + judge[1] + judge[2] + judge[3]) > 2) {
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}
	return 0;
}
