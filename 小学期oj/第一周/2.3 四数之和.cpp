#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums,int target){
    vector<vector<int>> res;
    //排序
    sort(nums.begin(),nums.end());
    //unique并不真正把重复的元素删除，是把重复的元素移到后面去了，然后依然保存到了原数组中
    //然后返回去重后最后一个元素的地址，因为unique去除的是相邻的重复元素，所以一般用之前都会要排一下序。
    //这时候用erase方法把当前位置到end的vector元素都删掉就可以了
    nums.erase(unique(nums.begin(),nums.end()),nums.end());//去重

    //4重循环,后两重用双指针算法
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            //双指针循环
            for(int k=j+1,l=nums.size()-1;k<l;k++){
                //预判下一个数，如果没有重叠，且下一个数满足
                while(k<l-1&&nums[i]+nums[j]+nums[k]+nums[l-1]>=target)l--;
                //判断是否找到和为target的4个数
                if(nums[i]+nums[j]+nums[k]+nums[l]==target)
                    res.push_back({nums[i],nums[j],nums[k],nums[l]});
            }
        }
    }
    return res;
}

bool comp(vector<int>&a,vector<int>&b){
    if(a[0]<b[0]) return true;
    else if(a[0]==b[0] && a[1]<b[1]) return true;
    else if(a[0]==b[0] &&a[1]==a[1]&&a[2]<b[2]) return true;
    else if(a[0]==b[0] &&a[1]==a[1]&&a[2]==b[2]&&a[3]<b[3]) return true;
    else return false;
}

int main(){
    int target,n,x;
     cin>>target>>n;
    vector<int> nums(n);
    vector<vector<int>>res;
   
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    //寻找三元组
    res=fourSum(nums,target);

    //输出三元组
    sort(res.begin(),res.end(),comp);
    for(auto line:res) cout<<line[0]<<" "<<line[1]<<" "<<line[2]<<" "<<line[3]<<endl;
    return 0;
}

