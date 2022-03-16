#include <ctype.h>
#include <stdio.h>
#include <string.h>

char ans[20] = { "ENDOFINPUT"};
int main() {
	char string[500];
	while (gets(string),strcmp(string,ans))
	{
		if(strcmp(string,"END") && strcmp(string,"START")){
			int len = strlen(string);
			for (int i = 0; i < len; i++) {
				if (isalpha(string[i])) {//如果是字母
					string[i] = (string[i] - 'A' - 5+26) % 26 + 'A';//直接取余就可以了！！
				}
			}
			printf("%s\n", string);	
		} 
		else if(!strcmp(string,"END")){
			continue;
		}  
		else if(!strcmp(string,"START")){
			continue;
		}  
		gets(string);
	}
	return 0;
}
