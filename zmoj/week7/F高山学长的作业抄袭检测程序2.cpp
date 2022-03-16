#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//nµÄ·¶Î§£º0-26 
int main() {
	char hw1[2000];
	char changehw1[110][15];
	while (gets(hw1)) {
		char* tok;
		tok = strtok(hw1, " ");
		int len = 0, num, count = 0;
		while (tok) {
			strcpy(changehw1[len], tok);
			len++;
			tok = strtok(NULL, " ");
		}
		num = atoi(changehw1[0]);
		for (int i = 1; i < len; i++) {
			int length = strlen(changehw1[i]);
			for (int j = 0; j < length; j++) {
				if (changehw1[i][j] >= 'A' && changehw1[i][j] <= 'Z') {
					changehw1[i][j] = 'A' + (changehw1[i][j] - 'A' + num) % 26;
				}
				else if (changehw1[i][j] >= 'a' && changehw1[i][j] <= 'z') {
					changehw1[i][j] = 'a' + (changehw1[i][j] - 'a' + num) % 26;
				}
			}
			if (i < len - 1) printf("%s ", changehw1[i]);
			else if (i == len - 1) printf("%s", changehw1[len - 1]);
		}
		printf("\n");
		memset(hw1, 0, sizeof hw1);
		for (int i = 0; i < 110; i++) {
			memset(changehw1[i], 0, sizeof changehw1[i]);
		}
	}
	return 0;
}
