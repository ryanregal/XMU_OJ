#include <stdio.h>
#include <string.h>

int main() {
	char code[26];
	char text[100];
	scanf("%s", code);
	int n = 0;
	char c = getchar();
	while (~scanf("%s", text) ) {
		if (n != 0) printf(" ");
		int str = strlen(text);
		for (int i = 0; i < str; i++) {
			for (int j = 0; j < 26; j++) {
				if (text[i] == code[j]) {
					printf("%c", j + 'A');
					break;
				}
			}
		}
		n=1;
	}
	return 0;
}

