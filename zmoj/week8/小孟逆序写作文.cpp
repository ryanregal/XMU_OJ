#include<stdio.h>
#include<string.h>

int main()
{
	char str[150];//存储所有字符串
	char words[10][130];//储存拆分字符串
	int flag = 0, pos, cnt = 0;

	while (fgets(str, 150, stdin) && str[0] != '\n') {
		if (strncmp(str, "#", 1) == 0 && flag==0) {
			//读到了表示开始#，直接进行下一轮循环
			flag = 1;
			continue;
		}
		if (strncmp(str, "#", 1) == 0 && flag==1) {
			//已经读过了#，说明现在的#表示结束，那么把word中的作文输出
			flag = 0;//下一次读的#重新表开始
			for (int k = 0; k < cnt; k++) {//对cnt个word进行输出
				pos = 0;//单词起始位置
				for (int i = 0; words[k][i]!=0; i++) {
					if (words[k][i] == ' ' || words[k][i] == '\n') {//找到结尾处
						for (int j = i - 1; j >= pos; j--) {//逆序输出字符串
							printf("%c", words[k][j]);
						}
						pos = i + 1;//记录下一个字符串新开始的位置
						printf("%c",words[k][i]);//空格空行不逆序
					}
				}
			}
			cnt = 0;
			continue;//下一篇作文
		}
		if (cnt < 10)
			strcpy(words[cnt++], str);//读到了字符串就存入拆分数组中
	}
	return 0;
}
