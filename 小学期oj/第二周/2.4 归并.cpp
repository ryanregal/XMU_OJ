#include<iostream>
using namespace std;

int q[1000010],t[1000010];

void merge_sort(int s[], int l, int r) {
	if (l >= r)return;
	int mid = (l + r) >> 1;

	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);

	int k = 0, m = l, n = mid + 1;
	while (m <= mid && n <= r) {
		if (q[m] <= q[n])
			t[k++] = q[m++];
		else
			t[k++] = q[n++];
	}
	while (m <= mid)t[k++] = q[m++];
	while (n <= r)t[k++] = q[n++];

	for (int i = l, k = 0; i <= r; i++, k++)q[i] = t[k];
}

int main() {
	int n,k;
	cin >> n;
    for (int i = 0; i < n; i++)scanf("%d",&q[i]);
	//for (int i = 0; i < n; i++)cin >> q[i];
	merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)printf("%d ", q[i]);
	//for (int i = 0; i < n; i++)cout << q[i]<<" ";
	return 0;
}