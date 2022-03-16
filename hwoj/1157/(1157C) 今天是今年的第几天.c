#include <stdio.h>

int main()
{
	int year,month,day;
	while (scanf("%d/%d/%d",&year,&month,&day) != EOF)
	{
		int sum=0;
        int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		year,month,day,sum=0;
        if(year%400==0||year%4==0&&year%100!=0){
        	a[2]=29;
		}
		else{
			a[2]=28;
		}
        a[0]=day;    
        for(int i=0;i<month;i++) sum+=a[i];
        printf("%d\n",sum);
	}
	return 0;
}
