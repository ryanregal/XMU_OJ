#include <stdio.h>
#include <stdlib.h>

long long int gcd(int a, int b) {//由最大公约数求最小公倍数
	long long int temp, c;
	if (a < b) temp = a, a = b, b = temp;
	long long int a1 = a, b1 = b;
	while (b != 0) {
		c = a % b, a = b, b = c;
	}
	c = b1 / a;
	long long int ans = a1 * c;
	return  ans;
}

int main() {
	int num;
    while(scanf("%d", &num)!=EOF){
    	long long int n[num];
		for (int i = 0; i < num; i++) {
			scanf("%d", &n[i]);
			if (i > 0) {
				n[i] = gcd(n[i], n[i - 1]);
			}
		}
		printf("%d\n", n[num - 1]);
	}
	return 0;
}
