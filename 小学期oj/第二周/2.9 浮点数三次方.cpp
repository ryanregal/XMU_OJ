#include<iostream>
#include<algorithm>
using namespace std;

int p[1000010];

double fun(double x,double target) {
	return x*x*x-target;
}

double binary(double l, double r, double target) {
	double eps = 1e-11;
	while (r - l > eps) {
		double mid = (l + r) / 2;
		if (fun(mid,target) > 0)
			r = mid;
		else l = mid;
	}
	return l;
}

int main() {
	double x;
	cin >> x;
	if(x>0)
	    printf("%.6lf", binary(0.0,x,x));
	else
		printf("%.6lf", binary(x,0.0,x));
	return 0;
}