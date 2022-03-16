#include <stdio.h>
#include <math.h>

int prime(int aj)
{
	for (int i = 2; i <= sqrt(aj) + 1; i++)
	{
		if (aj % i == 0 &&aj!=2 || aj==1) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int a = 0, d = 0, n = 0;
	while (scanf("%d %d %d", &a, &d, &n) != EOF) {
		int sum;
		for (int i = 0; n > 0; i++) {
			sum =a+i*d;
			if (prime(sum)) {
				n--;
			}	
		}
		printf("%d\n", sum);
	}
	return 0;
}


