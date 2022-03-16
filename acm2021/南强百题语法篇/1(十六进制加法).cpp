#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char s[20];
	char s1[20];
	while (scanf("%s%s", &s, &s1) != EOF) {
		int a = 0, b = 0,n1=strlen(s),n2=strlen(s1);

		if (s[0] == '-' || s[0] == '+') {
			for (int i = 1; i < n1; i++) {
				if (s[i] >= 'A' && s[i] <= 'Z') {
					s[i] = s[i] - 'A' + 10;
					a = a * 16 + s[i];
				}
				else if (s[i] >= '0' && s[i] <= '9') {
					s[i] -= '0';
					a = a * 16 + s[i];
				}
			}
			if (s[0] == '-') {
				a = a * (-1);
			}
		}
		else {
			for (int i = 0; i < n1; i++) {
				if (s[i] >= 'A' && s[i] <= 'Z') {
					s[i] = int(s[i] - 'A') + 10;
					a = a * 16 + s[i];
				}
				else if (s[i] >= '0' && s[i] <= '9') {
					s[i] -= '0';
					a = a * 16 + s[i];
				}
			}
		}

		if (s1[0] == '-' || s1[0] == '+') {
			for (int i = 1; i < n2; i++) {
				if (s1[i] >= 'A' && s1[i] <= 'Z') {
					s1[i] = s1[i] - 'A' + 10;
					b = b * 16 + s1[i];
				}
				else if (s1[i] >= '0' && s1[i] <= '9') {
					s1[i] -= '0';
					b = b * 16 + s1[i];
				}
			}
			if (s1[0] == '-') {
				b = b * (-1);
			}
		}
		else {
			for (int i = 0; i < n2; i++) {
				if (s1[i] >= 'A' && s1[i] <= 'Z') {
					s1[i] = int(s1[i] - 'A') + 10;
					b = b * 16 + s1[i];
				}
				else if (s1[i] >= '0' && s1[i] <= '9') {
					s1[i] -= '0';
					b = b * 16 + s1[i];
				}
			}
		}

		int sum = a + b;
		if (sum >= 0) {
			printf("%X\n", sum);
		}
		else if (sum < 0) {
			sum = abs(sum);
			printf("-%X\n", sum);
		}
	}
	return 0;
}

