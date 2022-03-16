//比较“放入不同箱子的的得分值+余下球放入属于自己的箱子的得分值”和“全放入自己箱子的得分值” 的大小
//推导公式
#include <iostream>
using namespace std;
int R, B, r, b, A;

int main() {
	cin >> R >> B >> r >> b >> A;
	if(r+b>2*A){
		//应该放在自己箱子
		cout << R * r + B * b;
		return 0;
	}
	else {//应该尽量放在别人的箱子
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
