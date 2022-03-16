#include <stdio.h>
int main()
{
	char s[10];
	while (scanf("%s", &s) != EOF){
		for (int i = 0; i < 10; i++){
			printf("%c", s[i]);
			if (i == 2 || i == 4){
				printf(" ");
			}
		}
		printf("\n");
	}
return 0;
}
