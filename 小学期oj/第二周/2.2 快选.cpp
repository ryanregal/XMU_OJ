/*
 * @Author: ryanregal 1822327087@qq.com
 * @Date: 2022-07-04 08:23:16
 * @LastEditors: ryanregal 1822327087@qq.com
 * @LastEditTime: 2022-07-04 08:33:57
 * @FilePath: \xmuoj\第二周\2.2 快选.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;
const int N = 1000010;
int q[N];


int quick_sort(int q[], int l, int r, int k) {
	if (l >= r)
		return q[l];
	int i = l - 1, j = r + 1, x = q[l + r >> 1];
	while (i < j) {
		do
			i++;
		while (q[i] < x);
		do
			j--;
		while (q[j] > x);
		if (i < j)
			swap(q[i], q[j]);
	}
	int sl = j - l + 1;
	if (sl >= k)
		return quick_sort(q, l, j, k);
	else
		return quick_sort(q, j + 1, r, k - sl);
}


int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	cout << quick_sort(q, 0, n - 1, k) << endl;
	return 0;
}
