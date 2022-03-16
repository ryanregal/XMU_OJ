#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	freopen("in.txt","r",stdin); 
	char name[100];
	char item[100];
	int x=0,y=0,count=0;
	double price=4.0;
	
	gets(name);
	x = (30 - strlen(name) - 2) / 2;
	y = 30 - strlen(name) -2 - x;
	
	printf("        #1 MT Takeaway\n\n");
	for (int i = 0; i < x; i++) {
		printf("-");
	}
	printf(" %s ",name);
	for (int i = 0; i < y; i++) {
		printf("-");
	}
	printf("\n");
	
	while (gets(item) != NULL)
	{
		double alone=0.0;
		for (int i = 0; i < 30; i++) {
			if (item[i] <= 57 && item[i] >= 48) {
				if (item[i + 1] <= 57 && item[i+1] >= 48) {
					count = (item[i]-48)*10+item[i+1]-48;
				}
				else{
					count=item[i]-48;
				}
				break;
			}
		}
		if (item[0] == 'D') {
			alone = 3.0 * count;
			printf("Dried bean curd     x%-2d%5.1lf\n", count,alone);
		}
		else if (item[0] == 'P') {
			alone = 2.5 * count;
			printf("Potato              x%-2d%5.1lf\n", count,alone);
		}
		else if (item[0] == 'S') {
			alone = 2.5 * count;
			printf("Sauteed lettuce     x%-2d%5.1lf\n", count,alone);
		}
		else if (item[0] == 'R') {
			alone = 1.0 * count;
			printf("Rice                x%-2d%5.1lf\n", count,alone);
		}
		else if (item[0] == 'F') {
			alone = 7.0 * count;
			printf("Fried beef pepper   x%-2d%5.1lf\n", count,alone);
		}
		else if (item[0] == 'L') {
			alone = 4.0 * count;
			printf("Lotus root soup     x%-2d%5.1lf\n", count,alone);
		}
		price += alone;
	}
	printf("Delivery fees: 4\n------------------------------\n");
	printf("                Total:%6.1lf", price);
	return 0;
}
