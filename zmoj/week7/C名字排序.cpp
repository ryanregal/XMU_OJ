#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	char s1[110][15] = { "\0" }, temp[1][15] = { "\0" };
	char s2[110][15] = { "\0" };
	char input[2000] = "\0";

	while (gets(input)) {
		int k = 0, m = 0, len = strlen(input);
		for (int z = 0; z < len; z++) {
			if (input[z] != ' ' && input[z]) {
				s1[k][m] = input[z];
				if (input[z] >= 'A' && input[z] <= 'Z') s2[k][m] = input[z] - 'A' + 'a';
				else if (input[z] >= 'a' && input[z] <= 'z') s2[k][m] = input[z];
				m++;
			}
			else {
				s1[k][m] = '\0';
				m = 0, k++;
			}
		}
		//单词数量为k+1
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k - i; j++) {
				if (strcmp(s2[j], s2[j + 1]) > 0) {
					strcpy(temp[0], s1[j + 1]);
					strcpy(s1[j + 1], s1[j]);
					strcpy(s1[j], temp[0]);
					strcpy(temp[0], s2[j + 1]);
					strcpy(s2[j + 1], s2[j]);
					strcpy(s2[j], temp[0]);
				}
			}
		}
		printf("%s", s1[0]);
		for (int i = 1; i <= k; i++) {
			printf(" %s", s1[i]);
		}
		printf("\n");
		memset(temp, 0, sizeof temp);
		for (int i=0;i<=k;i++){
			memset(s1[i], 0, sizeof s1[i]);
			memset(s2[i], 0, sizeof s2[i]);
		}
	}
	return 0;
}

