#include <stdio.h>
#include <math.h>
int main() {
	int t;
	scanf("%d", &t);
	int loc[t][3];
	for (int i=0;i<t;i++)
	{
		double x, y, r;
		scanf("%lf%lf%lf", &x, &y, &r);
		loc[i][0] = x, loc[i][1] = y, loc[i][2] = r;
	}
	int p;
	scanf("%d", &p);
	int flag = 1;
	for(int i=0;i<t;i++){
		if(i==p) continue;
		double dir = sqrt(pow((loc[p][0] - loc[i][0]), 2) + pow((loc[p][1] - loc[i][1]), 2));
		if (dir<=(loc[p][2]+loc[i][2]))
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1) printf("Alive\n");
	else if (flag == 0) printf("Biu\n");
	return 0;
}
