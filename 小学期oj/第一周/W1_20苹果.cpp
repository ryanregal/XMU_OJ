#include <iostream>
using namespace std;

int func(int apple, int plate) {
	if (apple < plate)	// ƻ����С��������
		return func(apple, apple);
	if (apple == 0)		// ûƻ���� һ�ְڷ�����ȫ��
		return 1;
	if (plate <= 0)		// û������ û�аڷ�
		return 0;
	return func(apple, plate - 1) + func(apple - plate, plate);
	// ��һ�����ӵķ��� + ÿ����������һ���İڷ�
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