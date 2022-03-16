#include <stdio.h>
#include <stdlib.h>

int maxSubArrayPosition(int* nums,int numsSize,int *reslen) {
	int start = 0,end = 0,newsize=0;
	*reslen = newsize;
	int subStart = 0,subEnd = 0;
	int max = nums[0];    // ȫ�����ֵ
	int subMax = nums[0];  // ǰһ������ϵ����ֵ
	for (int i = 1; i < numsSize; i++) {
		if (subMax >= 0) {// ǰһ����������ֵ���ڵ���0���������Ԫ��λ��
			subMax = subMax + nums[i];
			subEnd++;
			newsize = subEnd - subStart + 1;
		}
		else {// ����ǰ��Ľ�������µ�ǰ���ֵλ��
			subMax = nums[i];
			subStart = i,subEnd = i;
			newsize = subEnd - subStart + 1;
		}
		// ȫ�����Ž��λ�ø���
		if (subMax > max||(subMax==max && newsize>(*reslen))) {
			max = subMax;
			start = subStart,end = subEnd;
			*reslen = newsize;
		}
	}
	return max;
}

int main() {
	int n;
	while (scanf("%d", &n)!=EOF)
	{
		int reslen, max;
		int array[n];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &array[i]);
		}
		max = maxSubArrayPosition(array, n, &reslen);
		printf("%d %d\n", max, reslen);
	}
}
