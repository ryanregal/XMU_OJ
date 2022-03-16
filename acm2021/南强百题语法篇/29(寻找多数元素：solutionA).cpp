#include <stdio.h>
//方法一：Boyer-Moore 投票算法
/*如果把众数记为+1，其他数记为-1，全部加起来，显然和大于 0。
详细步骤：
1、维护一个候选众数candidate和它出现次数count。初始count为 0。 
2、遍历数组中所有元素，如果 count 的值为 0，先将元素的值赋予 candidate，随后判断：
	x与candidate相等，count++；不等，count--。
3、遍历完成，candidate即为整个数组的众数。*/ 
//时间复杂度O(n),空间复杂度O(1) 

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

