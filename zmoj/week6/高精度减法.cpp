#include <stdio.h>
#include <string.h>

char s[100],ss[100];
int a[100],b[100];
int len;    
void de()
{
    int l1 = strlen(s);    
    int l2 = strlen(ss);
    int flag = 0;         
    memset(a,0,sizeof(a));       
    memset(b,0,sizeof(b));  

    if ( l1 < l2 || (strcmp(s,ss) < 0 && l1 == l2) )    //ǰ�������Ĵ�С
    {                                          
        flag = 1; //������¼
        for (int i = l2 - 1 ; i >= 0 ; i--)    //���������� 
            a[l2 - i - 1] = ss[i] - '0';      //�ַ�ת��Ϊ���֣�aΪ������bΪС�� 
        for (int i = l1 - 1 ; i >= 0 ; i--)
            b[l1 - i - 1] = s[i] - '0'; 
    }
    else
    {
        for (int i = l1 - 1 ; i >= 0 ; i--)   
            a[l1 - i - 1] = s[i] - '0';
        for (int i = l2 - 1 ; i >= 0 ; i--)
            b[l2 - i - 1] = ss[i] - '0';
    }
    if (l1 > l2)     len = l1;             //len��ֵΪ���д���� 
    else len = l2; 
    for (int i = 0 ; i < len ; i++)
    {
        a[i] = a[i] - b[i];     //���� 
        if (a[i] < 0)          //������ö��� 
        {
            a[i+1]-=1;         //��ǰҪһλ 
            a[i]+=10;          
        }
    }
    while (a[len - 1] == 0 && len>1) len--;   //whileȥ��
    if (flag == 1) printf("-");     //�������Ǹ��ģ������һ������ 
    for (int i = len - 1 ;i >= 0 ;i--)   //�������� 
        printf("%d",a[i]);
    printf("\n");   //���� 
}                          

int main()
{
    while (scanf("%s%s",s,ss)!=EOF)
    {
        de();    //�߾��ȼ�������
    }
    return 0;
}


