
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const double PI=acos(-1.0);
const double eps=1e-6;
double Cakes[10005];
int N,F;

bool hasEnoughCake(double sizeofCake){
    if(sizeofCake<eps) return true;
    int count=0;
    for(int i=0;i<N;i++){
        if(sizeofCake>Cakes[i]) continue;
        int pieces=Cakes[i]/sizeofCake;
        count+=pieces;
        if(count>=F) return true;
    }
    return false;
}

double binarySearch(double nums[],int n){
    double left=nums[0]/F,right=nums[n-1];
    while(right-left>eps){
        double mid=left+(right-left)/2;
        if(hasEnoughCake(mid)) left=mid+eps;
        else right=mid;
    }
    return left;
}

int main(){
    int r;
    scanf("%d%d",&N,&F);
    F++;
    for(int i=0;i<N;i++){
        scanf("%d",&r);
        Cakes[i]=r*r;
    }
    sort(Cakes,Cakes+N);
    double sizeofCake=binarySearch(Cakes,N);
    printf("%.3lf\n",sizeofCake*PI);
    return 0;
}



