/*
icebear:约数和模数问题
应用定理：
①整数的唯一分解定理：
②约数和公式：
③同余模公式：
  (a*b)% m=(a%m * b%m) %m
*/

#include<iostream>
using namespace std;

//二进制取幂法
int qmi(int a, int b){
	int ans = 1;
	a = a % 9901;
	while (b){
		if (b & 1) {
			ans = (ans * a) % 9901;
		}
		a = a * a % 9901;
		b >>= 1;//二进制数b右移一位
	}
	return ans;
}

//求等比数列和
//1+p+…+p^c=?
int sum(int p, int c){
	if (c == 0) return 1;//c=0时返回1
	//公式推导见P17
	if (c % 2 == 0) {
		return ((1 + qmi(p, c / 2)) * sum(p, c / 2 - 1) + qmi(p, c)) % 9901;
	}
	else return ((1 + qmi(p, (c + 1) / 2)) * sum(p, (c - 1) / 2)) % 9901;
}

int main(){
	int a, b;
	cin >> a >> b;
	int ans = 1;//1是a的约数
	//遍历求a的约数p1,p2……pn
	//由乘法分配律得A^B约数和公式：sum(p1,b*c1)*…*sum(pn,b*cn)
	for (int p = 2; p <= a; p++){
		int c = 0;
		while (a % p == 0){
			a /= p;
			c++;
		}
		ans = ans * sum(p, c * b) % 9901;
	}
	if (!a) ans = 0;//a可能是0
	cout << ans << endl;
}

