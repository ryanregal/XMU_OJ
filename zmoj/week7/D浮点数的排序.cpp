#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_neg_dig(char* a) {
	int dig = 0;
	for (int j = 1; a[j] != '.'; j++) {
		dig++;
	}
	return dig;
}

int get_pos_dig(char* a) {
	int dig = 0;
	for (int j = 0; a[j] != '.'; j++) dig++;
	return dig;
}

int main() {
	char c[80000];
	char temp[52];
	while (gets(c) != NULL) {
		char a[1500][52];
		memset(a, '\0', sizeof(a));
		char* tok;
		tok = strtok(c, " ");
		int len = 0;
		while (tok) {
			strcpy(a[len], tok);
			len++;
			tok = strtok(NULL, " ");
		}

		char neg_a[1500][52];
		char pos_a[1500][52];
		memset(neg_a, '\0', sizeof(neg_a));
		memset(pos_a, '\0', sizeof(pos_a));
		int neg_a_len = 0,pos_a_len = 0;

		for (int p = 0; p < len; p++) {
			if (a[p][0] == '-') strcpy(neg_a[neg_a_len++], a[p]);
			else strcpy(pos_a[pos_a_len++], a[p]);
		}

		for (int i = 0; i < neg_a_len - 1; i++) {
			for (int m = i + 1; m < neg_a_len; m++) {
				if (get_neg_dig(neg_a[i]) < get_neg_dig(neg_a[m])) {
					strcpy(temp, neg_a[i]);
					strcpy(neg_a[i], neg_a[m]);
					strcpy(neg_a[m], temp);
				}
				else if (get_neg_dig(neg_a[i]) == get_neg_dig(neg_a[m])) {
					if (strcmp(neg_a[i], neg_a[m]) <= 0) {
						strcpy(temp, neg_a[i]);
						strcpy(neg_a[i], neg_a[m]);
						strcpy(neg_a[m], temp);
					}
				}
			}
		}

		for (int i = 0; i < pos_a_len - 1; i++) {
			for (int m = i + 1; m < pos_a_len; m++) {
				if (get_pos_dig(pos_a[i]) > get_pos_dig(pos_a[m])) {
					strcpy(temp, pos_a[i]);
					strcpy(pos_a[i], pos_a[m]);
					strcpy(pos_a[m], temp);
				}
				else if (get_pos_dig(pos_a[i]) == get_pos_dig(pos_a[m])) {
					if (strcmp(pos_a[i], pos_a[m]) >= 0) {
						strcpy(temp, pos_a[i]);
						strcpy(pos_a[i], pos_a[m]);
						strcpy(pos_a[m], temp);
					}
			    }
			}		
		}
		for (int i = 0; i < neg_a_len; i++)
			printf("%s ", neg_a[i]);
		for (int i = 0; i < pos_a_len; i++)
			printf(" %s" + !i, pos_a[i]);
		putchar('\n');
	}
	return 0;
}


