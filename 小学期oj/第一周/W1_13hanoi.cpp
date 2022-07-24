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
	// ��n-1�����Ӵ�start�ŵ�tmp
	Hanoi(n - 1, start, target, tmp);
	// ��������һ�����ӷŵ�target
	move(start, target);
	// ��n-1�����Ӵ�tmp�ŵ�target
	Hanoi(n - 1, tmp, start, target);
}

int main() {
	int n; // ���Ӹ���
	cin >> n;
	Hanoi(n, 'A', 'B', 'C');

	return 0;
}