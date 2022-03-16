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

    if ( l1 < l2 || (strcmp(s,ss) < 0 && l1 == l2) )    //前后两数的大小
    {                                          
        flag = 1; //正负记录
        for (int i = l2 - 1 ; i >= 0 ; i--)    //倒过来输入 
            a[l2 - i - 1] = ss[i] - '0';      //字符转换为数字，a为大数，b为小数 
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
    if (l1 > l2)     len = l1;             //len赋值为其中大的数 
    else len = l2; 
    for (int i = 0 ; i < len ; i++)
    {
        a[i] = a[i] - b[i];     //运算 
        if (a[i] < 0)          //如果减得多了 
        {
            a[i+1]-=1;         //向前要一位 
            a[i]+=10;          
        }
    }
    while (a[len - 1] == 0 && len>1) len--;   //while去零
    if (flag == 1) printf("-");     //如果结果是负的，先输出一个负号 
    for (int i = len - 1 ;i >= 0 ;i--)   //再输出结果 
        printf("%d",a[i]);
    printf("\n");   //换行 
}                          

int main()
{
    while (scanf("%s%s",s,ss)!=EOF)
    {
        de();    //高精度减法函数
    }
    return 0;
}


