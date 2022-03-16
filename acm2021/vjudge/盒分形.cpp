/*
icebear:�з���
n�ȵĺз��εĹ�ģ������3^(n-1)��������
���õݹ麯��Box(n,x,y)��
�ٵݹ�߽磺 ��n=1,���ڣ�x,y�������X��
����n>1,��ֱ������ϣ� ���ϣ��м䣬���º����»���5��n-1�ȵĺ��ӡ����ӹ�ģm = 3^(n-2)
 ��1�����Ϸ�����x,y��
 ��2  ���Ϸ�����x+2m,y��
 ��3���м䣺  ��x+m,y+m��
 ��4�����·�����x,y+2m��
 ��5�����Ϸ�����x+2m,y+2m��
*/

#include <math.h>
#include <stdio.h>
//7�Ⱥз��� ����ģn=3^6=729
#define MAX 730

char maps[MAX][MAX];//����ͼ�ε�����

void Box(int n, int x, int y)
{
	//�ݹ�߽�
	if (n == 1) {
		maps[x][y] = 'X';
	}
	else {
		int m = pow(3, n - 2);//n-1�Ⱥз��εĹ�ģm
		Box(n - 1, x, y);//���Ϸ���n-1�Ⱥз���
		Box(n - 1, x + 2 * m, y);//���Ϸ���n-1�Ⱥз���
		Box(n - 1, x, y + 2 * m);//�м��n-1�Ⱥз���
		Box(n - 1, x + m, y + m);//���·���n-1�Ⱥз���
		Box(n - 1, x + 2 * m, y + 2 * m);//���·���n-1�Ⱥз���
	}

}

int main()
{
	int n,i,j;
	scanf("%d", &n);
	while (n != -1) {
		int size = pow(3, n - 1);
		//��ʼ��
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				maps[i][j] = ' ';
				maps[i][size] = '\0';
			}
		}
		Box(n, 0, 0);
		for (i = 0; i < size; i++)	printf("%s\n", maps[i]);
		printf("-\n");
		scanf("%d", &n);
	}
	return 0;
} 
