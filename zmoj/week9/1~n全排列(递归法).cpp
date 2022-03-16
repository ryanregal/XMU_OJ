#include<stdlib.h>
#include <stdio.h>
int a[100];
//用于打表，oj上直接递归输出超限 
void dfs(int cur, int* n)//cur表示目前填的数，n表示总共要填的数 
{
	if (cur == *n)//递归边界
	{
		printf("(");
		for (int i = 0; i < *n; i++) {//一个一个的输出 
			printf("%d", a[i]);
			if (i!=*n-1)	printf(", ");
		}
		printf(")");
	}
	for (int i = 1; i <= *n; i++)//把数字1-n填入 
	{
		int flag = 1;
		for (int j = 0; j < cur; j++)//遍历目前a数组里面的元素，判断当前这个数有没有填过（用过） 
		{
			if (a[j] == i) flag = 0;
		}
		if (flag == 1)
		{
			a[cur] = i;//没有填过,放在a数组的最后 
			dfs(cur + 1, n);//再排第cur+1个位置 
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
