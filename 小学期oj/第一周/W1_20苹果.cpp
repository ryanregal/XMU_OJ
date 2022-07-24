#include <iostream>
using namespace std;

int func(int apple, int plate) {
	if (apple < plate)	// 苹果数小于盘子数
		return func(apple, apple);
	if (apple == 0)		// 没苹果了 一种摆法——全空
		return 1;
	if (plate <= 0)		// 没盘子了 没有摆法
		return 0;
	return func(apple, plate - 1) + func(apple - plate, plate);
	// 空一个盘子的方法 + 每个盘子至少一个的摆法
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int apple, plate;
		cin >> apple >> plate;
		cout << func(apple, plate) << endl;
	}

	return 0;
}