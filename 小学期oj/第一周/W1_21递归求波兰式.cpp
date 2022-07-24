#include <iostream>
using namespace std;

#include <cmath>
#include <string>

// * + 11.0 12.0 + 24.0 35.0

double func() {
	string s;
	cin >> s;
	switch (s[0])
	{
	case '+':return func() + func(); break;
	case '-':return func() - func(); break;
	case '*':return func() * func(); break;
	case '/':return func() / func(); break;
	default:
		return stof(s);
		break;
	}
}

int main() {
	printf("%lf", func());
	return 0;
}