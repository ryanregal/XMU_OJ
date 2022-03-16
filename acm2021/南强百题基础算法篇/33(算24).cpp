/*�ݹ顣ÿ�δ�������ȡ�������������������㣬�õ�һ���������������б������һ����
�ٰ�����õ������ŵ����鵱�У��ٴν��к����ĵ��ã����ͻ�ֻʣ��һ������
����������24����ô���ܹ��ɹ�������ʧ�ܡ��������ַŷ������������*/
#include <cmath>
#include <iostream>
using namespace std;
#define spacesize 4
#define EPS 1e-6
double inputnumber[spacesize + 1];

bool isZero(double x) { return fabs(x) <= EPS;}
bool count24(double a[], int n) {//n���Ϊ���������С
	if (n==1)//��������
	{
		if (isZero(a[0] - 24)) return true;
		else return false;
	}
	//ö��ȡ��������
	for (int i=0;i<n-1;i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double* temp = new double[n - 1];//����temp���飬����Ҫ�����n-1����
			int iTemp = 0;
			for (int k = 0; k < n; k++) {
				if ((k != i) && (k != j)) temp[iTemp++] = a[k];
			}
			//�������������������ֵ
			temp[iTemp] = a[i] + a[j];
			if (count24(temp, n - 1)) return true;
			temp[iTemp] = a[i] * a[j];
			if (count24(temp, n - 1)) return true;
			temp[iTemp] = a[i] - a[j];
			if (count24(temp, n - 1)) return true;
			temp[iTemp] = a[j] - a[i];
			if (count24(temp, n - 1)) return true;
			if (!isZero(a[j])) {//������Ϊ0
				temp[iTemp] = a[i] / a[j];
				if (count24(temp, n - 1)) return true;
			}
			if (!isZero(a[i])) {//������Ϊ0
				temp[iTemp] = a[j] / a[i];
				if (count24(temp, n - 1)) return true;
			}
		}
	}
	return false;//ǰ��ȫ������return˵���޷��ճ�24
}

int main() {
	while (true)
	{
		bool isENDInput = true;//�ж��Ƿ���0 0 0 0��ʾ����
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
