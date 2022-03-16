#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long* numbers;

void quicksort(long long nums[], int left, int right) {
	//初始时left是0，right是n-1;
	if (left>=right) return;
	//选取分割数
	long long target = nums[left];//选取第一个分割数
	int i = left - 1, j = right + 1;//i是left的左边一位，j是right的右边一位
	while (i<j)
	{
		do {
			i++;
		} while (nums[i]<target);//i定位到左边第一个>=target的数
		do {
			j--;
		} while (nums[j]>target);//j指针定位到右边第一个<=target的数
		if (i<j)
		{
			swap(nums[i], nums[j]);
		}
	}
	//i=j，分而治之！
	quicksort(nums, left, j);
	quicksort(nums, j + 1, right);
}

int main() {
	//cin\cout提速
	ios::sync_with_stdio(false);//取消iostream的输入输出缓存
	cin.tie(0);//解除cin和cout的绑定
	int n;
	cin >> n;
	numbers = new long long[n];//创建动态数组
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	quicksort(numbers, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << numbers[i] << ' ';
	}
	delete numbers;
	return 0;
}
