#include<iostream>
#include<algorithm>
using namespace std;
const int N=1000010;
int q[N];
int main(){
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++) cin>>q[i];
    cin>>k;
    sort(q,q+n);
    for(int j=0;j<k;j++){
        cout<<q[n-j-1]<<endl;
    }
    return 0;
}