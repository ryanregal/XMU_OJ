#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > threeSum(vector<int>& nums, int target) {
	vector< vector<int> >res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (i && nums[i] == nums[i - 1]) continue;//Ìø¹ýÖØ¸´¶¥
		for (int j = i + 1, k = nums.size() - 1; j < k; j++)
		{
			if (j > (i + 1) && (nums[j] == nums[j - 1])) continue;
			while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= target)k--;
			if (nums[i] + nums[j] + nums[k] == target)
			{
				res.push_back({ nums[i],nums[j],nums[k] });
			}
		}
	}
	return res;
}

bool comp(vector<int>& a, vector<int>& b) {
	if (a[0] < b[0] || (a[0] == b[0] && a[1] < b[1])) {
		return true;
	}
	else return false;
}

int main() {
	int target, n, x;
	vector<int>a;
	vector<vector<int>> res;
	cin >> target >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
	}
	res = threeSum(a, target);
	sort(res.begin(), res.end(), comp);
	for (auto line : res)
	{
		cout << line[0] << " " << line[1] << " " << line[2] << endl;
	}
	return 0;
}
