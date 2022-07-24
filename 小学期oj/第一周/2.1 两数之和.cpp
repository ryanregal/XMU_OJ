#include <iostream>
#include <vector>
using namespace std;
int main(){
    int target,n,x;
    cin>>target>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    for(int i=0,j=n-1;i<=j;i++){
        //循环直到两数之和小于或者等于目标
        //等于就跳出循环
        //小于则很自然地让i++，nums[i]变得更大去试探。
        while(j>i&&nums[i]+nums[j]>target)j--;
        if(nums[i]+nums[j]==target){
            cout<<i<<" "<<j<<endl;
            break;
        }
    }
    return 0;
}