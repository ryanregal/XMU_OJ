#include<stdio.h>
#include<string.h>

int main()
{
	char str[150];//�洢�����ַ���
	char words[10][130];//�������ַ���
	int flag = 0, pos, cnt = 0;

	while (fgets(str, 150, stdin) && str[0] != '\n') {
		if (strncmp(str, "#", 1) == 0 && flag==0) {
			//�����˱�ʾ��ʼ#��ֱ�ӽ�����һ��ѭ��
			flag = 1;
			continue;
		}
		if (strncmp(str, "#", 1) == 0 && flag==1) {
			//�Ѿ�������#��˵�����ڵ�#��ʾ��������ô��word�е��������
			flag = 0;//��һ�ζ���#���±�ʼ
			for (int k = 0; k < cnt; k++) {//��cnt��word�������
				pos = 0;//������ʼλ��
				for (int i = 0; words[k][i]!=0; i++) {
					if (words[k][i] == ' ' || words[k][i] == '\n') {//�ҵ���β��
						for (int j = i - 1; j >= pos; j--) {//��������ַ���
							printf("%c", words[k][j]);
						}
						pos = i + 1;//��¼��һ���ַ����¿�ʼ��λ��
						printf("%c",words[k][i]);//�ո���в�����
					}
				}
			}
			cnt = 0;
			continue;//��һƪ����
		}
		if (cnt < 10)
			strcpy(words[cnt++], str);//�������ַ����ʹ�����������
	}
	return 0;
}
