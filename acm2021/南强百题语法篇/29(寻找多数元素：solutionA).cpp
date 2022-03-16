#include <stdio.h>
//����һ��Boyer-Moore ͶƱ�㷨
/*�����������Ϊ+1����������Ϊ-1��ȫ������������Ȼ�ʹ��� 0��
��ϸ���裺
1��ά��һ����ѡ����candidate�������ִ���count����ʼcountΪ 0�� 
2����������������Ԫ�أ���� count ��ֵΪ 0���Ƚ�Ԫ�ص�ֵ���� candidate������жϣ�
	x��candidate��ȣ�count++�����ȣ�count--��
3��������ɣ�candidate��Ϊ���������������*/ 
//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1) 

int main() {
	int num;
	int candidate,cnt = 0;
	while (scanf("%d",&num)==1)
	{
		char c=getchar();
		if(c=='\n'){
			break;
		}
		if (cnt == 0) {
			candidate = num;
			cnt = 1;
		}
		else if (num == candidate) {
			cnt++;
		}
		else if (num != candidate) {
			cnt--;
		}
	}
	printf("%d", candidate);
	return 0;
}

