#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int  a=1,b=1;
		for (int i = n-1; i>0; i--)//�����ݼ������Ƽ��㣩
		{   
			b =2*(b + 1);//����ÿһ��ĳ�����
			a = b + a;//������������ܺ�
		}
		printf("%d\n",b);
	}
	return 0;
}

