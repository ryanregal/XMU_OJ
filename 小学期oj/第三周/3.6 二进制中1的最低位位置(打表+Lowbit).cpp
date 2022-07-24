#include<iostream>
using namespace std;
#define MaxN 16
int log2[1<<MaxN];  //65536
// 打表法计算log2[1<<16]
void BuildLog2Table(int n)
{
    for(int k=0;k<=n;k++)
        log2[1<<k]=k; 
}
int lowbit(int n){
    return n & -n; //!-n表示n取反+1
}
int PosOf1(int n){
    return log2[lowbit(n)];
}
int main()
{
    BuildLog2Table(MaxN);
    int n; cin>>n;
    cout<<PosOf1(n);
}
