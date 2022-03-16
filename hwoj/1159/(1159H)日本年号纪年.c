#include <stdio.h>
#include <math.h>
int main()
{
	int month, day, add, year;
	char input[10];
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int b[500];
	for (int i = 0; i < 500; i++) {
			int temp = i + 1868;
			if ((temp % 4 == 0 && temp % 100 != 0) || temp % 400 == 0) {
				b[i] = 366;
			}
			else {
				b[i] = 365;
			}
	}
	
	while (scanf("%s %d", &input, &add) != EOF)
	{
		//将输入字符串转换为三个数字记录的日期 
		int an = 0;
		year = day = month = 0;
		for (int i = 0; i < 10; i++) {
			if (input[i] == '/' && input[i + 2] == '/') {
				month = input[i + 1] - 48;
				an = i + 3;
				break;
			}
			else if (input[i] == '/' && input[i + 3] == '/') {
				month = (input[i + 1] - 48) * 10 + (input[i + 2] - 48);
				an = i + 4;
				break;
			}
		}

		if (input[an + 1] != '\0') {
			day = (input[an] - 48) * 10 + (input[an + 1] - 48);
		}
		else if (input[an + 1] == '\0') {
			day = input[an] - 48;
		}

		if (input[2] != '/') {
			year += (input[1] - 48) * 10;
			year += input[2] - 48;
		}
		else if (input[2] == '/') {
			year += input[1] - 48;
		}

		if (input[0] == 'M') {
			year += 1868 - 1;
		}
		else if (input[0] == 'T') {
			year += 1912 - 1;
		}
		else if (input[0] == 'S') {
			year += 1926 - 1;
		}
		else if (input[0] == 'H') {
			year += 1989 - 1;
		}
		else if (input[0] == 'R') {
			year += 2019 - 1;
		}

		a[1] = (b[year - 1868] == 366)? 29:28;

		//1868年1月1日为第一天，求输入日期+add为第几天 
		int num;
		num=add;
		for (int i = 0; i < month - 1; i++) {
			num += a[i];
		}
		num += day;
		for (int j = 1868; j < year; j++) {
			num += b[j-1868];
		}
		//进行输出 
		int com = 0, com1 = 0,year1=0;
		for (int i = 1868; i < 2090; i++) {
 			com += b[i - 1868];
			if (com >= num) {
				year=i;
				com = num-(com-b[i - 1868]);//今年的第几天 
				break;
			}
		}
		a[1] = (b[year - 1868] == 366)? 29:28;
		
		for (int j = 0; j < 12; j++) {
			com1 += a[j];
			if (com1 >= com) {
				month = j+1;
				day=com-(com1-a[j]);
				break;
			}
		}

		if (num < 16282) {
			year1=year-1868+1;
			printf("M%d/%d/%d\n", year1, month, day);
		}
		else if (num >= 16282 && num < 21543) {
			year1=year-1912+1;
			printf("T%d/%d/%d\n", year1, month, day);
		}
		else if (num >= 21543 && num <= 44202) {
			year1=year-1926+1;
			printf("S%d/%d/%d\n", year1, month, day);
		}
		else if (num >= 44203 && num <= 55272) {
			year1=year-1989+1;
			printf("H%d/%d/%d\n", year1, month, day);
		}
		else if (num >= 55273) {
			year1=year-2019+1;
			printf("R%d/%d/%d\n", year1, month, day);
		}

		for (int i = 0; i < 10; i++) {
			input[i] = '\0';
		}
	}
	return 0;
}
