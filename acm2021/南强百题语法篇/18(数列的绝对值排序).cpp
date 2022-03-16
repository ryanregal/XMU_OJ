#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool less_abs(int a, int b) {
	return abs(a) > abs(b);
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		vector <int> nums;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			nums.push_back(x);
		}
		sort(nums.begin(), nums.end(), less_abs);
		for (int i=0;i<m-1;i++)
		{
			cout << nums[i] << " ";
		}
		cout << nums[m - 1] << endl;
	}
	return 0;
}
