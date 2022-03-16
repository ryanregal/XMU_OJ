#include <stdio.h>
#include <string.h>

int main()
{
	int num = 0;
	char s[500];//ÊäÈëµÄ×Ö·û´®	
	while (scanf("%d %s", &num, &s) != EOF) {
		int flag=1;
		char stack[500];//´æ×óÀ¨ºÅµÄÕ»
		int top = 0;//Õ»¶¥ 
		int l=strlen(s); 

		for (int i = 0; i < l; i++) {
			if (s[i] == '(' && flag==1) {
				stack[top] = s[i];
				top++;//×óÀ¨ºÅÈëÕ» 
			}
			else if (s[i] == ')') {
				if (top > 0) {
					top--;
				}
				else {
					flag=0;
				}
			}
			s[i]='\0';
		}
		if (top!=0) {//Èç¹ûÕ»²»¿Õ£¬ÓĞÊ£Óà×óÀ¨ºÅ 
			flag=0;
		}
		
		if(flag==0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}


