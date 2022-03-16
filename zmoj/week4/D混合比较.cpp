#include <stdio.h>

int main() {
	int x, y, z,max=0,sign;
	scanf("%d%d%d", &x, &y, &z);
	for (int i = 0; i < x; i++) {
		int dec;
		scanf("%d", &dec);
		if (dec > max) {
			max = dec;
			sign = 10;
		}
	}
	for (int i = 0; i < y; i++) {
		int oct;
		scanf("%o", &oct);
		if (oct > max) {
			max = oct;
			sign = 8;
		}
	}
	for (int i = 0; i < z; i++) {
		int x;
		scanf("%x", &x);
		if (x > max) {
			max = x;
			sign = 16;
		}
	}
	if (sign == 10) printf("%d", max);
	else if (sign == 8) printf("%o", max);
	else if (sign == 16) printf("%x", max);
	return 0;
}
