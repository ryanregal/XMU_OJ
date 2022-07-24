#include <algorithm>
#include <iostream>
#include<vector>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,a,i;
        cin>>n;
        vector<int>nums;
        for(i=0;i<n;i++){
            cin>>a;
            nums.push_back(a);
        }
        sort(nums.begin(),nums.end());
        for(i=0;i<n-1;i++) cout<<nums[i]<<" ";
        cout<<nums[i]<<endl;
    }
    return 0;
}