#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > fourSum(vector<int>& nums, int target) {
	vector< vector<int> >res;
	sort(nums.begin(), nums.end());
	//四重循环，后两重用双指针算法
	for (int i = 0; i < nums.size(); i++)
	{
		if (i && nums[i] == nums[i - 1]) continue;//跳过重复顶
		for (int j = i + 1; j < nums.size(); j++) {
			if (j>i+1 && nums[j] == nums[j - 1]) continue;//跳过重复顶
			for (int k = j + 1, l = nums.size() - 1; k < l; k++)
			{
				if (k > (j + 1) && (nums[k] == nums[k - 1])) continue;
				while (k < l - 1 && nums[i] + nums[j] + nums[k]+nums[l-1] >= target)l--;
				if (nums[i] + nums[j] + nums[k] +nums[l]== target)
				{
					res.push_back({ nums[i],nums[j],nums[k],nums[l]});
				}
			}
		}
	}
	return res;
}

bool comp(vector<int>& a, vector<int>& b) {
	if (a[0] < b[0] || (a[0] == b[0] && a[1] < b[1])||(a[0]==b[0]&&a[1]==b[1]&&a[2]<b[2])) {
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
	res = fourSum(a, target);
	sort(res.begin(), res.end(), comp);
	for (auto line : res)
	{
		cout << line[0] << " " << line[1] << " " << line[2] <<" "<<line[3] << endl;
	}
	return 0;
}
