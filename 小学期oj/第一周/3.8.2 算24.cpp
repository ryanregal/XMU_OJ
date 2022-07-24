#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    vector<int> a(4);
    while(cin>>a[0]>>a[1]>>a[2]>>a[3] && a[0]|a[1]|a[2]|a[3]){
        if(count24(a,0.0)) cout <<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

bool count24(vector<int>a,double res){
    //递归出口
    if(a.empty()){
        return fabs(res-24)<0.000001;
    }
    //枚举
    for(int i=0;i<a.size();i++){
        vector<int>b(a); //拷贝啊
        b.erase(b.begin()+i);
        if(count24(b,res+a[i])||count24(b,res-a[i])||count24(b,res-a[i])||count24(b,res*a[i])||count24(b,res/a[i])){
            return true;
        }
    }
    return false;
}







