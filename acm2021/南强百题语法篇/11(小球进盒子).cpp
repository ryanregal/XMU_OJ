//�Ƚϡ����벻ͬ���ӵĵĵ÷�ֵ+��������������Լ������ӵĵ÷�ֵ���͡�ȫ�����Լ����ӵĵ÷�ֵ�� �Ĵ�С
//�Ƶ���ʽ
#include <iostream>
using namespace std;
int R, B, r, b, A;

int main() {
	cin >> R >> B >> r >> b >> A;
	if(r+b>2*A){
		//Ӧ�÷����Լ�����
		cout << R * r + B * b;
		return 0;
	}
	else {//Ӧ�þ������ڱ��˵�����
		if (R >= B) {
			cout << B * A * 2 + (R - B) * r;
				return 0;
		}
		else {
			cout << R * A * 2 + (B - R) * b;
			return 0;
		}

	}
} 
