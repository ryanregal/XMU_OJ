#include <stdio.h>
#include <string.h>

int main() {
	char hw1[2000], hw2[2000];
	char changehw1[110][15], changehw2[110][15];
	while (gets(hw1)) {
		gets(hw2);
		char* tok;
		tok = strtok(hw1, " ");
		int len = 0, len1 = 0;;
		while (tok) {
			strcpy(changehw1[len], tok);
			len++;
			tok = strtok(NULL, " ");
		}
		tok = strtok(hw2, " ");
		while (tok) {
			strcpy(changehw2[len1], tok);
			len1++;
			tok = strtok(NULL, " ");
		}
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len; j++) {
				if (strcmp(changehw2[i], changehw1[j]) == 0) {
					printf("(%d,%d)", i, j);
				}
			}
		}
		printf("\n");
		memset(hw1, 0, sizeof hw1);
		memset(hw2, 0, sizeof hw2);
		for (int i=0;i<=110;i++){
			memset(changehw1, 0, sizeof changehw1);
			memset(changehw2, 0, sizeof changehw2);
		}
	}
	return 0;
}


