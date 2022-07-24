#include <iostream>
using namespace std;

void move(int id, char start, char target) {
	cout << id << ":" << start << "->" << target << endl;
	return;
}

void Hanoi(int n, int id, char start, char tmp, char target) {
	if (n == 1) {
		move(id, start, target);
		return;
	}
	// ��n-1�����Ӵ�start�ŵ�tmp
	Hanoi(n - 1, id, start, target, tmp);
	// ��������һ�����ӷŵ�target
	move(id + n - 1, start, target);
	// ��n-1�����Ӵ�tmp�ŵ�target
	Hanoi(n - 1, id, tmp, start, target);
}

int main() {
	int n; // ���Ӹ���
	char a, b, c;
	cin >> n >> a >> b >> c;
	Hanoi(n, 1, a, b, c);

	return 0;
}