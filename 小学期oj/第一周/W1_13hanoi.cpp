#include <iostream>
using namespace std;

void move(char start, char target) {
	cout << start << "->" << target << endl;
	return;
}

void Hanoi(int n, char start, char tmp, char target) {
	if (n == 1) {
		move(start, target);
		return;
	}
	// 把n-1个盘子从start放到tmp
	Hanoi(n - 1, start, target, tmp);
	// 把最下面一个盘子放到target
	move(start, target);
	// 把n-1个盘子从tmp放到target
	Hanoi(n - 1, tmp, start, target);
}

int main() {
	int n; // 盘子个数
	cin >> n;
	Hanoi(n, 'A', 'B', 'C');

	return 0;
}