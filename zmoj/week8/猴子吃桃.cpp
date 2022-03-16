#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int  a=1,b=1;
		for (int i = n-1; i>0; i--)//天数递减（倒推计算）
		{   
			b =2*(b + 1);//计算每一天的吃桃数
			a = b + a;//计算吃桃数的总和
		}
		printf("%d\n",b);
	}
	return 0;
}

