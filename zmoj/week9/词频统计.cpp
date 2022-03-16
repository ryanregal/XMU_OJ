#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word{
	char word[100];
	int freq;
}word;

int cmp(const void *x, const void * y){
	int a = ((word*)x)->freq;
	int b = ((word*)y)->freq;
	if (a < b) return 1;
	else if (a > b) return -1;
	else if (a == b) {
		if (strcmp(((word*)x)->word, ((word*)y)->word) > 0) {
			return -1;
		}
		else return 1;
	}
}

int main() {
	char str[10000];
	while (gets(str)!=0) {
		int count=0;//µ¥´ÊÊıÁ¿
		struct word get[100];
		char* tok;
		tok = strtok(str, " ");
		while (tok) {
			int flag = 0;
			for (int i=0;i<count;i++){
				if (strcmp(get[i].word, tok)==0) {
					get[i].freq++;
					flag = 1;
					break;
				}
				else continue;
			}
			if (flag==0){
				strcpy(get[count].word, tok);
				get[count].freq = 1;
				count++;
			}
			tok = strtok(NULL, " ");
		}
		qsort(get, count, sizeof(word), cmp);
		for (int i=0;i<count;i++){
			printf("%s(%d)", get[i].word, get[i].freq);
			if (i != count - 1) printf(" ");
			else printf("\n");
			memset(get[i].word, 0, sizeof(100));
			get[i].freq = 0;
		}
		memset(str,0,1000*sizeof(int));
	}
}
