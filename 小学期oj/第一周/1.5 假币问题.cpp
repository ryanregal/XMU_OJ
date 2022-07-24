#include <cstring>
#include <iostream>
using namespace std;

string Left[3];//��ƽ���
string Right[3];//��ƽ�ұ�
string result[3];

//isLightΪ���ʾ�ٱ�Ϊ�ᣬ�����ʾ����ٱ�Ϊ��
bool isFeitCoin(char iCoin, bool isLight) {
	string c;
	c.push_back(iCoin);//char ת��Ϊstring
	for (int i = 0; i < 3; i++) {
		string l = Left[i], r = Right[i];
		if (!isLight)
			swap(l, r); //�ٱ�Ϊ�أ�����һ���ж�
		//�ж�c�Ƿ�Ϊ�ٱ�
		switch (result[i][0]) { //��ƽ�ұߵ����
			case 'e': //����ƽ��
				//find () ������������һ��ģ�庯����������ָ����Χ�ڲ��Һ�Ŀ��Ԫ��ֵ��ȵĵ�һ��Ԫ��
				//���û�ҵ�������һ���ر�ı�־c++����npos��ʾ��npos��һ����������ʾsize_t�����ֵ
				//����ƽ�����ƽ���Ҷ������
				if (l.find(c) != string::npos || r.find(c) != string::npos)
					return false;
				break;
			case 'u'://�Ҷˣ��ߵ���һ��û���ҵ�Ӳ��
				if (r.find(c) == string::npos)
					return false;
				break;
			case 'd'://��ˣ��ߵ���һ��û���ҵ�Ӳ��
				if (l.find(c) == string::npos)
					return false;
				break;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 3; ++i) {
			cin >> Left[i] >> Right[i] >> result[i];
		}
		//ö�����е����ң��Ƿ��Ǽٱҵ��������
		for (char iCoin = 'A'; iCoin <= 'L'; iCoin++) {
			if (isFeitCoin(iCoin, true)) {
				cout << iCoin << " is the counterfeit coin and it is light. " << endl;
				break;
			} else if (isFeitCoin(iCoin, false)) {
				cout << iCoin << " is the counterfeit coin and it is heavy. " << endl;
				break;
			}
		}
	}
	return 0;
}

