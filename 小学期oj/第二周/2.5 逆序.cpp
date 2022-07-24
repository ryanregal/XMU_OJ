#include<iostream>
using namespace std;

int q[1000010],t[1000010];
typedef long long ll;

ll merge_sort(int s[], int l, int r) {
	if (l >= r)return 0;
	int mid = (l + r) >> 1;
	ll res=	merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

	int k = 0, m = l, n = mid + 1;
	while (m <= mid && n <= r) {
		if (q[m] <= q[n])
			t[k++] = q[m++];
		else {
			t[k++] = q[n++];
			res += mid - m + 1;//加上左边mid与m之间的逆序个数，
			//因为m号元素大于右侧某元素，故从m到mid号元素均大于右侧该元素
		}
	}
	while (m <= mid)t[k++] = q[m++];
	while (n <= r)t[k++] = q[n++];

	for (int i = l, k = 0; i <= r; i++, k++)q[i] = t[k];
	return res;
}


int main() {
	int n;
	cin >> n;
    for (int i = 0; i < n; i++)scanf("%d",&q[i]);
	//for (int i = 0; i < n; i++)cin >> q[i];
	cout<<merge_sort(q, 0, n - 1)<<endl;
    //for (int i = 0; i < n; i++)printf_s("%d ", q[i]);
	//for (int i = 0; i < n; i++)cout << q[i]<<" ";
	return 0;
}