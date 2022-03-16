/*
icebear:Լ����ģ������
Ӧ�ö���
��������Ψһ�ֽⶨ��
��Լ���͹�ʽ��
��ͬ��ģ��ʽ��
  (a*b)% m=(a%m * b%m) %m
*/

#include<iostream>
using namespace std;

//������ȡ�ݷ�
int qmi(int a, int b){
	int ans = 1;
	a = a % 9901;
	while (b){
		if (b & 1) {
			ans = (ans * a) % 9901;
		}
		a = a * a % 9901;
		b >>= 1;//��������b����һλ
	}
	return ans;
}

//��ȱ����к�
//1+p+��+p^c=?
int sum(int p, int c){
	if (c == 0) return 1;//c=0ʱ����1
	//��ʽ�Ƶ���P17
	if (c % 2 == 0) {
		return ((1 + qmi(p, c / 2)) * sum(p, c / 2 - 1) + qmi(p, c)) % 9901;
	}
	else return ((1 + qmi(p, (c + 1) / 2)) * sum(p, (c - 1) / 2)) % 9901;
}

int main(){
	int a, b;
	cin >> a >> b;
	int ans = 1;//1��a��Լ��
	//������a��Լ��p1,p2����pn
	//�ɳ˷������ɵ�A^BԼ���͹�ʽ��sum(p1,b*c1)*��*sum(pn,b*cn)
	for (int p = 2; p <= a; p++){
		int c = 0;
		while (a % p == 0){
			a /= p;
			c++;
		}
		ans = ans * sum(p, c * b) % 9901;
	}
	if (!a) ans = 0;//a������0
	cout << ans << endl;
}

