#include <iostream>
#include <cmath>
using namespace std;
double PolishNotation() {
	char str[32];
	cin >> str;
	switch (str[0])
	{
	case '+':return PolishNotation() + PolishNotation();
		break;
	case '-':return PolishNotation() - PolishNotation();
		break;
	case '*':return PolishNotation() * PolishNotation();
		break;
	case '/':return PolishNotation() / PolishNotation();
	default:
		return atof(str);
	break;
	}
}
int main() {
	printf("%lf", PolishNotation());
	return 0;
}
