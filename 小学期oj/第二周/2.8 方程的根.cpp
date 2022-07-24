#include<iostream>
using namespace std;

double f(double x){
    return x*x*x-5*x*x+10*x-80;
}

double bsearch_d1(double l,double r){
    double eps=1e-11;
    while(r-l>eps){
        double mid=(l+r)/2;
        if(f(mid)>0) r=mid;
        else l=mid;
    }
    return l;
}

int main(){
    printf("%.9lf\n",bsearch_d1(0.0,10.0));
    return 0;
}