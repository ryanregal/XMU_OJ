#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums,int target){
    vector<vector<int>> res;
    //排序
    sort(nums.begin(),nums.end());
    //unique并不真正把重复的元素删除，是把重复的元素移到后面去了，然后依然保存到了原数组中
    //然后返回去重后最后一个元素的地址，因为unique去除的是相邻的重复元素，所以一般用之前都会要排一下序。
    //这时候用erase方法把当前位置到end的vector元素都删掉就可以了
    nums.erase(unique(nums.begin(),nums.end()),nums.end());//去重

    //3重循环
    for(int i=0;i<nums.size();i++){
        //双指针循环
        for(int j=i+1,k=nums.size()-1;j<k;j++){
            //预判下一个数，如果下一个数k与j没有重叠，且下一个数满足
            //nums[i]+nums[j]+nums[k-1]>=target,则移动k指针，k--
            while(j<k-1&&nums[i]+nums[j]+nums[k-1]>=target)k--;
            //判断是否找到和为target的三个数
            if(nums[i]+nums[j]+nums[k]==target)
                res.push_back({nums[i],nums[j],nums[k]});
        }
    }
    return res;
}

bool comp(vector<int>&a,vector<int>&b){
    if(a[0]<b[0]) return true;
    else if(a[0]==b[0] && a[1]<b[1]) return true;
    else if(a[0]==b[0] &&a[1]==b[1]&&a[2]<b[2]) return true;
    else return false;
}

int main(){
    int target,n,x;
    cin>>target>>n;
    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
     vector<vector<int>>res;
    //寻找三元组
    res=threeSum(nums,target);
    //输出三元组
    sort(res.begin(),res.end(),comp);
    for(auto line:res) cout<<line[0]<<" "<<line[1]<<" "<<line[2]<<endl;
    return 0;
}
