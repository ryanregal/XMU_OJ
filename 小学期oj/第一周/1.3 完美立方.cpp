#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	for (int a = 2; a <= N; ++a) {
		for (int b = 2; b <= a - 1; ++b) {
			for (int c = b; c <= a - 1; ++c) {
				for (int d = c; d <= a - 1; ++d) {
					if (a * a * a == b * b * b + c * c * c + d * d * d) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
					}
				}
			}
		}
	}
	return 0;
}