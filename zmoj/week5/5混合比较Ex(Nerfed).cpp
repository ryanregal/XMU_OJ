#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(void const* a, void const* b) {
	return *((int*)a) - *((int*)b);
}

int main() {
	char a[10000];
	int num[100];
	scanf("%s", a);
	int str = strlen(a);
	char tmp[100][100];
	int i=0,j=0;
	for (int k=0; i < str;) {
		if (a[i] != ',') {
		    tmp[j][k] = a[i];
			i++, k++;
		}
		else if (a[i] == ',') {
			i++, j++;
			k=0;
		}
	}
	for (int t=0;t<(j+1);t++)
	{
		if(tmp[t][0]=='0' && tmp[t][1] != 'x' && tmp[t][1] != 'b') num[t] = strtol(tmp[t], NULL, 8);
		else if (tmp[t][0] == '0'&&tmp[t][1]=='x') num[t] = strtol(tmp[t], NULL, 16);
		else if (tmp[t][0] == '0' && tmp[t][1] == 'b') {
			for (int c = 0;tmp[t][c]!='\0'; c++) {
				tmp[t][c] = tmp[t][c + 2];
			}
			num[t] = strtol(tmp[t], NULL, 2);	
		}
		else num[t] = strtol(tmp[t], NULL, 10);
	}
	qsort(num, j+1, sizeof(num[0]), cmp);
	for (int s=0;s<j;s++)
	{
		printf("%d,", num[s]);
	}
	printf("%d",num[j]);
	return 0;
}
