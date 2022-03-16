#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmp(const void* a, const void* b) {//指针不可变，值可变
	return *((int*)a) - *((int *)b);
}

int main() {
	char t1[10000];
	char t2[10000];
	int num[10000] = { 0 };
	while (gets(t1)){
		int count = 0;
		char* tok;
		tok = strtok(t1, " ");
		while (tok) {
			num[count] = atoi(tok);
			count++;
			tok = strtok(NULL, " ");
		}
		gets(t2);
		tok = strtok(t2, " ");
		while (tok) {
			num[count] = atoi(tok);
			count++;
			tok = strtok(NULL, " ");
		}
		qsort(num, count, sizeof(int), cmp);
		for (int i=0;i<count;i++){
			printf("%d", num[i]);
			if (i != count - 1) printf(" ");
		}
		printf("\n");
		memset(t1, 0, count);
		memset(t2, 0, count);
	}
}
