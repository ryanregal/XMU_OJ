#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long* numbers;

void quicksort(long long nums[], int left, int right) {
	//��ʼʱleft��0��right��n-1;
	if (left>=right) return;
	//ѡȡ�ָ���
	long long target = nums[left];//ѡȡ��һ���ָ���
	int i = left - 1, j = right + 1;//i��left�����һλ��j��right���ұ�һλ
	while (i<j)
	{
		do {
			i++;
		} while (nums[i]<target);//i��λ����ߵ�һ��>=target����
		do {
			j--;
		} while (nums[j]>target);//jָ�붨λ���ұߵ�һ��<=target����
		if (i<j)
		{
			swap(nums[i], nums[j]);
		}
	}
	//i=j���ֶ���֮��
	quicksort(nums, left, j);
	quicksort(nums, j + 1, right);
}

int main() {
	//cin\cout����
	ios::sync_with_stdio(false);//ȡ��iostream�������������
	cin.tie(0);//���cin��cout�İ�
	int n;
	cin >> n;
	numbers = new long long[n];//������̬����
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
