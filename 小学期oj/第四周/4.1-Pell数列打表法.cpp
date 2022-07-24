#include<iostream>
using namespace std;
const int Max = 1000001;
int a[Max];
void buildPell(int n){
    a[1]=1;a[2]=2;
    for(int i=3;i<=n;i++)
        a[i] = (2*a[i-1]+a[i-2])%32767;
}
int main()
{
    int m,n;
    cin>>m;
    buildPell(Max);
    while(m--){
        cin>>n;
        cout<<a[n]%32767<<endl;
    }
}
