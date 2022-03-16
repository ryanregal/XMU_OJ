#include <stdio.h>
#include <string.h>
int main() {
	char hw1[2000], hw2[2000];
	char changehw1[110][15], changehw2[110][15], ans[110][15];
	while (gets(hw1) && gets(hw2)) {
		memset(ans, 0, sizeof(ans));
		memset(changehw1, 0, sizeof changehw1);
		memset(changehw2, 0, sizeof changehw2);
		int flag = 0, judge = 0, len1 = 0, len2 = 0;;
		char* tok;
		tok = strtok(hw1, " ");
		while (tok) {
			strcpy(changehw1[len1], tok);
			len1++;
			tok = strtok(NULL, " ");
		}
		tok = strtok(hw2, " ");
		while (tok) {
			strcpy(changehw2[len2], tok);
			len2++;
			tok = strtok(NULL, " ");
		}

		for (int k = 0; k < 26; k++) {
			flag = 0;
			for (int i = 0; i < len2; i++) {
				for (int j = 0; j < len1; j++) {
					if (strlen(changehw1[j]) ==strlen(changehw2[i])) {
						int test = 1;
						for (int m = 0; changehw1[j][m] != '\0'; m++) {
							char temp;
							if (changehw1[j][m] >= 'A' && changehw1[j][m] <= 'Z') {
								temp = 'A' + (changehw1[j][m] - 'A' + k) % 26;
							}
							else if (changehw1[j][m] >= 'a' && changehw1[j][m] <= 'z') {
								temp = 'a' + (changehw1[j][m] - 'a' + k) % 26;
							}
							else temp = changehw1[j][m];
							if (temp == changehw2[i][m]) continue;
							else {
								test = 0;
								break;
							}
						}
						if (test) {
							if (flag == 0)printf("+%d ", k);
							printf("(%d,%d)", i, j);
							judge = 1;
							flag = 1;
						}
					}
				}
			}
			if (flag == 1) printf("\n");
		}
		if (judge == 0)printf("No\n");
	}
	return 0;
}
