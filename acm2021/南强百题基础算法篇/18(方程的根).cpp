#include <iostream>
#include <cmath>
using namespace std;
#define EPS 0.000000009
double f(double x) {
	return x * x * x - 5 * x * x + 10 * x - 80;
}
double binarysearch(double left, double right) {
	double mid;
	while ( (right-left) >=EPS)
	{
		mid = left + (right - left) / 2.0;
		if (f(mid) > 0) right = mid;
		else left = mid+EPS;
	}
	return mid;
}
int main() { 
	double  x =binarysearch(0.0, 10.0);
	printf("%.9lf\n", x);
}
