#include <stdio.h>
#include <string.h>

int main()
{
	int num = 0;
	char s[500];//������ַ���	
	while (scanf("%d %s", &num, &s) != EOF) {
		int flag=1;
		char stack[500];//�������ŵ�ջ
		int top = 0;//ջ�� 
		int l=strlen(s); 

		for (int i = 0; i < l; i++) {
			if (s[i] == '(' && flag==1) {
				stack[top] = s[i];
				top++;//��������ջ 
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
		if (top!=0) {//���ջ���գ���ʣ�������� 
			flag=0;
		}
		
		if(flag==0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}


