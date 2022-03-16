#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int factor_value();//递归函数读入并处理因子
int term_value();//递归函数读入并处理项
int expression_value();//递归函数读入并处理表达式

int main() {
	cout << expression_value() << endl;
	return 0;
}

int expression_value() {//求表达式值
	int result = term_value();//第一项的值	
	bool more = true;
	while (more)
	{
		char op = cin.peek();//看一个字符，不取走
		if (op == '+' || op == '-')//加减运算
		{
			cin.get();//从输入中取走一个字符
			int value = term_value();//建立双向判断循环
			if (op == '+') result += value;
			else result -= value;
		}
		else more = false;
	}
	return result;
}

int term_value() {//求一个乘除项的值
	int result = factor_value();//求第一个数字的值
	while (true)
	{
		char op = cin.peek();
		if (op == '*' || op == '/')
		{
			cin.get();
			int value = factor_value();
			if (op == '*') result *= value;
			else result /= value;
		}
		else break;
	}
	return result;
}

int factor_value() {//求一个数字的值
	int result = 0;
	char c = cin.peek();
	if (c=='(')
	{
		cin.get();
		result = expression_value();
		cin.get();//读入右括号
	}
	else {
		while (isdigit(c))
		{
			result = 10 * result + c - '0';//按字符读入十进制数
			cin.get();
			c = cin.peek();
		}
	}
	return result;
}

