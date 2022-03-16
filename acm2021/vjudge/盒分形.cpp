/*
icebear:盒分形
n度的盒分形的规模：长宽3^(n-1)的正方形
设置递归函数Box(n,x,y)：
①递归边界： 若n=1,则在（x,y）输出‘X’
②若n>1,则分别在左上， 右上，中间，左下和右下画出5个n-1度的盒子。盒子规模m = 3^(n-2)
 （1）左上方：（x,y）
 （2  右上方：（x+2m,y）
 （3）中间：  （x+m,y+m）
 （4）左下方：（x,y+2m）
 （5）右上方：（x+2m,y+2m）
*/

#include <math.h>
#include <stdio.h>
//7度盒分形 最大规模n=3^6=729
#define MAX 730

char maps[MAX][MAX];//储存图形的数组

void Box(int n, int x, int y)
{
	//递归边界
	if (n == 1) {
		maps[x][y] = 'X';
	}
	else {
		int m = pow(3, n - 2);//n-1度盒分形的规模m
		Box(n - 1, x, y);//左上方的n-1度盒分形
		Box(n - 1, x + 2 * m, y);//右上方的n-1度盒分形
		Box(n - 1, x, y + 2 * m);//中间的n-1度盒分形
		Box(n - 1, x + m, y + m);//左下方的n-1度盒分形
		Box(n - 1, x + 2 * m, y + 2 * m);//右下方的n-1度盒分形
	}

}

int main()
{
	int n,i,j;
	scanf("%d", &n);
	while (n != -1) {
		int size = pow(3, n - 1);
		//初始化
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
