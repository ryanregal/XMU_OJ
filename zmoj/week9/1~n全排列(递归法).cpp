#include<stdlib.h>
#include <stdio.h>
int a[100];
//���ڴ��oj��ֱ�ӵݹ�������� 
void dfs(int cur, int* n)//cur��ʾĿǰ�������n��ʾ�ܹ�Ҫ����� 
{
	if (cur == *n)//�ݹ�߽�
	{
		printf("(");
		for (int i = 0; i < *n; i++) {//һ��һ������� 
			printf("%d", a[i]);
			if (i!=*n-1)	printf(", ");
		}
		printf(")");
	}
	for (int i = 1; i <= *n; i++)//������1-n���� 
	{
		int flag = 1;
		for (int j = 0; j < cur; j++)//����Ŀǰa���������Ԫ�أ��жϵ�ǰ�������û��������ù��� 
		{
			if (a[j] == i) flag = 0;
		}
		if (flag == 1)
		{
			a[cur] = i;//û�����,����a�������� 
			dfs(cur + 1, n);//���ŵ�cur+1��λ�� 
		}
	}
}
int main()
{
	int n;
	while (scanf("%d",&n)){
		dfs(0, &n);
		printf("\n");
	}
	return 0;
}
