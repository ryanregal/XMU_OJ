#include <iostream>
using namespace std;
int N;
int stairs(int n){
    if(n==0) return 1;//一步都不走
    if(n==1) return 1;
    return stairs(n-1)+stairs(n-2);
}
int main(){
    cin>>N;
    cout<<stairs(N)<<endl;
    return 0;
}