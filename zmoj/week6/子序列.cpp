#include <stdio.h>
#include <stdlib.h>

int maxSubArrayPosition(int* nums,int numsSize,int *reslen) {
	int start = 0,end = 0,newsize=0;
	*reslen = newsize;
	int subStart = 0,subEnd = 0;
	int max = nums[0];    // 全局最大值
	int subMax = nums[0];  // 前一个子组合的最大值
	for (int i = 1; i < numsSize; i++) {
		if (subMax >= 0) {// 前一个子组合最大值大于等于0，更新最后元素位置
			subMax = subMax + nums[i];
			subEnd++;
			newsize = subEnd - subStart + 1;
		}
		else {// 抛弃前面的结果，更新当前最大值位置
			subMax = nums[i];
			subStart = i,subEnd = i;
			newsize = subEnd - subStart + 1;
		}
		// 全局最优解的位置更新
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
