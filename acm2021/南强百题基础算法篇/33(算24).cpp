/*递归。每次从数组中取出两个数进行四则运算，得到一个数，于是数组中便减少了一个数
再把运算得到的数放到数组当中，再次进行函数的调用，最后就会只剩下一个数。
这个数如果是24，那么就能够成功，否则失败。依据这种放法遍历所有情况*/
#include <cmath>
#include <iostream>
using namespace std;
#define spacesize 4
#define EPS 1e-6
double inputnumber[spacesize + 1];

bool isZero(double x) { return fabs(x) <= EPS;}
bool count24(double a[], int n) {//n最初为输入数组大小
	if (n==1)//结束条件
	{
		if (isZero(a[0] - 24)) return true;
		else return false;
	}
	//枚举取出两个数
	for (int i=0;i<n-1;i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double* temp = new double[n - 1];//创建temp数组，储存要处理的n-1个数
			int iTemp = 0;
			for (int k = 0; k < n; k++) {
				if ((k != i) && (k != j)) temp[iTemp++] = a[k];
			}
			//分六种情况求两数计算值
			temp[iTemp] = a[i] + a[j];
			if (count24(temp, n - 1)) return true;
			temp[iTemp] = a[i] * a[j];
			if (count24(temp, n - 1)) return true;
			temp[iTemp] = a[i] - a[j];
			if (count24(temp, n - 1)) return true;
			temp[iTemp] = a[j] - a[i];
			if (count24(temp, n - 1)) return true;
			if (!isZero(a[j])) {//除数不为0
				temp[iTemp] = a[i] / a[j];
				if (count24(temp, n - 1)) return true;
			}
			if (!isZero(a[i])) {//除数不为0
				temp[iTemp] = a[j] / a[i];
				if (count24(temp, n - 1)) return true;
			}
		}
	}
	return false;//前面全部都不return说明无法凑成24
}

int main() {
	while (true)
	{
		bool isENDInput = true;//判断是否是0 0 0 0表示结束
		for (int i=0;i<spacesize;i++)
		{
			cin >> inputnumber[i];
			if (!isZero(inputnumber[i]))isENDInput = false;
		}
		if (isENDInput)break;
		if (count24(inputnumber, spacesize)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
