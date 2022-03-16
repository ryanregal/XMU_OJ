#include <stdio.h>
#include <math.h>
#include <string.h>

void hourinput(char* a, int* h, int* m, int* ss) {//将输入的时间字符串转化 
	for (int i = 0; i < 2; i++) {
		*h += (a[i] - '0') * pow(10, 1 - i);
	}
	for (int j = 3; j < 5; j++) {
		*m += (a[j] - '0') * pow(10, 4 - j);
	}
	for (int k = 6; k < 8; k++) {
		*ss += (a[k] - '0') * pow(10, 7 - k);
	}
	return;
}

void dateinput(char* a, int* yy, int* mm, int* dd)//将输入的日期字符串转化 
{
	for (int i = 0; i < 4; i++) {
		*yy += (a[i] - '0') * pow(10, 3 - i);
	}
	for (int j = 5; j < 7; j++) {
		*mm += (a[j] - '0') * pow(10, 6 - j);
	}
	for (int k = 8; k < 10; k++) {
		*dd += (a[k] - '0') * pow(10, 9 - k);
	}
	return;
}

void judge(int* a, int* a1, int num, int* b) {
	int remain = 0, quo = 0;//余数和商 	
		if (*a >= *a1 && num != 12) *a -= *a1;
		else if (*a < *a1 || (num == 12 && *a == *a1)) {
			quo = (*a1 - *a) / num;
			remain = (*a1 - *a) % num;
			if(remain==0 && num!=12){
				*b-=quo;
				*a=0;
			} 
			else{
				*a = num - remain;
				*b -= (quo + 1);
			}
		
		}
	return;
}

void judge1(int* a, int* a1, int num, int* b) {
	int remain = 0, quo = 0;//余数和商 
	if (*a + *a1 < num||(num==12 && *a+*a1==num)) *a += *a1;
	else if (*a + *a1 >= num ) {
		quo = (*a1 + *a) / num;
		remain = (*a1 + *a) % num;
		if(num==12&&remain==0){
			*a=12;
			*b+=quo-1;
		}
		else{
			*a = remain;
			*b += quo;
		}
	}
	return;
}

void change(int* savv, int* x) {
	if ((*x % 4 == 0 && *x % 100 != 0) || *x % 400 == 0) {
		savv[2] = 29;
	}
	else {
		savv[2] = 28;
	}
	return;
}

int main() {
	char sign;
	char date[20]; char time[10]; char dplus[10]; char tplus[10];

	int save[13] = { 31,31,28,31,30,31,30,31,31,30,31,30,31 };//a[0]为方便判断day<=save[i-1] 
	void hourinput(char* a, int* hour, int* min, int* s);
	void dateinput(char* a, int* year, int* month, int* day);
	void judge(int* a, int* a1, int num, int* b);
	void judge1(int* a, int* a1, int num, int* b);
	void change(int* save, int* x);

    scanf("%s %s %c %s %s", &date, &time, &sign, &dplus, &tplus);
	int year = 0, month = 0, day = 0, hour = 0, min = 0, s = 0, hour1 = 0, min1 = 0, s1 = 0, dp = 0;

	dateinput(date, &year, &month, &day);
	hourinput(time, &hour, &min, &s);

	for (int i = strlen(dplus)-1; i >=0; i--){  
		dp += (dplus[i] - '0') * pow(10, strlen(dplus)-i-1);//需要加减的天数 
	}
	hourinput(tplus, &hour1, &min1, &s1); //需要加减的时间
	int tempp = 0;
	change(save, &year);

	if (sign == '-') {
		judge(&s, &s1, 60, &min);
		judge(&min, &min1, 60, &hour);
		judge(&hour, &hour1, 24, &day);
		day -= dp;
		while (day <= 0) {
			day += save[month - 1];
			month--;
			if (month <= 0) {
				judge(&month, &tempp, 12, &year);
			}
			change(save, &year);
		}
	}
	else if (sign == '+') {
		judge1(&s, &s1, 60, &min);
		judge1(&min, &min1, 60, &hour);
		judge1(&hour, &hour1, 24, &day);
		day += dp;
		while (day > save[month]) {
			day -= save[month];
			month++;
			if (month > 12) {
				judge1(&month, &tempp, 12, &year);
			}
			change(save, &year);
		}
	}
	printf("%04d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, min, s);
	return 0;
}
