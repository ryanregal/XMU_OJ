#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int frequency(char* substr, char* str);
int main(){
	char sub[1024], str[1024];
	while (scanf("%s%s", str, sub)!=EOF){
		int n = frequency(sub, str);
		printf("%d time(s)\n", n);
		memset(sub, 0, sizeof(sub)), memset(str, 0, sizeof(str));
	}
	return 0;
}

int frequency(char* substr, char* str){
	int n = 0, s1 = strlen(str), s2 = strlen(substr);
	char* p = str;
	while (s1 >= s2){
		str = strstr(str, substr);
		if (str != 0) {
			n++;
			str++;
		}
		else break;
		s1 = strlen(str);
	}
	return n;
}

