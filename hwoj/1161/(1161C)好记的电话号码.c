#include <stdio.h>
int main()
{
	char a[50];
	while (scanf("%s", &a) != EOF)
	{
		for (int i = 0; i < 50; i++)
		{
			if (a[i] == '\0') {
				break;
			}
			else if ((a[i] >= 48) && (a[i] <= 57)) {
				printf("%c", a[i]);
			}
			else if (a[i] == '-') {
				continue;
			}
			else if ((a[i] >= 65 && a[i] <= 67) || (a[i] >= 65 + 32 && a[i] <= 67 + 32)) {
				printf("2");
			}
			else if ((a[i] >= 68 && a[i] <= 70) || (a[i] >= 68 + 32 && a[i] <= 70 + 32)) {
				printf("3");
			}
			else if ((a[i] >= 71 && a[i] <= 73) || (a[i] >= 71 + 32 && a[i] <= 73 + 32)) {
				printf("4");
			}
			else if ((a[i] >= 74 && a[i] <= 76) || (a[i] >= 74 + 32 && a[i] <= 76 + 32)) {
				printf("5");
			}
			else if ((a[i] >= 77 && a[i] <= 79) || (a[i] >= 77 + 32 && a[i] <= 79 + 32)) {
				printf("6");
			}
			else if ((a[i] >= 80 && a[i] <= 83) || (a[i] >= 80 + 32 && a[i] <= 83 + 32)) {
				printf("7");
			}
			else if ((a[i] >= 84 && a[i] <= 86) || (a[i] >= 84 + 32 && a[i] <= 86 + 32)) {
				printf("8");
			}
			else if ((a[i] >= 87 && a[i] <= 90) || (a[i] >= 87 + 32 && a[i] <= 90 + 32)) {
				printf("9");
			}
		}
		printf("\n");
	}
	return 0;
}
