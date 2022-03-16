#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a;
		cin >> n;
		vector<int> nums;
		for (int i=0;i<n;i++)
		{
			cin >> a;
			nums.push_back(a);
		}
		sort(nums.begin(), nums.end());
		for (int j=0;j<n-1;j++)
		{
			cout << nums[j] <<" ";
		}
		cout << nums[n-1] << endl;
	}
	return 0;
}
