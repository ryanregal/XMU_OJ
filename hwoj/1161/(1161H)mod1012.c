#include <stdio.h>
/*�˻���ȡ�����ȡ��ĳ˻�*/
int main()
{
    const int c = 1012;
    int a, b;
	long long int outcom;
 
    while(scanf("%d%d", &a, &b )!=EOF){
    	outcom = 1;
	    if(!a && !b){ //a b��Ϊ����ֹͣѭ��
	        break;
	    }
	    for(int i=0; i<b; i++){
	        outcom = outcom *a % c;
	    }
		printf("%d\n", outcom);
    }
    return 0;
}
