#include <stdio.h>
#include <string.h>

void reverse(char *s, int len)
{
    int i, j;
    char temp;

    for (i = 0, j = len-1; i < j; ++i, --j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void multiply(char *a, int len_a, char *b, int len_b, char *product)
{
    int ptr_a, ptr_b, ptr_int_prod, ptr_prod, len_prod, carry, temp;
    int int_prod[2005] = { 0 };

    reverse(a, len_a);
    reverse(b, len_b);

    ptr_int_prod = 0;
    
	for (ptr_b = 0; ptr_b < len_b; ++ptr_b)
    {
        ptr_int_prod = ptr_b;
        for (ptr_a = 0; ptr_a < len_a; ++ptr_a, ++ptr_int_prod)
            int_prod[ptr_int_prod] += (a[ptr_a] - '0') * (b[ptr_b] - '0');
    }
    
    len_prod = ptr_int_prod;
    carry = 0;
    
    for (ptr_int_prod = 0; ptr_int_prod < len_prod; ++ptr_int_prod)
    {
        temp = (int_prod[ptr_int_prod] + carry) / 10;
        int_prod[ptr_int_prod] = (int_prod[ptr_int_prod] + carry) % 10;
        carry = temp;
    }
    
    while (carry > 0)
    {
        temp = carry / 10;
        int_prod[ptr_int_prod] = carry % 10;
        carry = temp;
        ptr_int_prod++;
        len_prod++;
    }

    ptr_int_prod = len_prod - 1;
    
    while (ptr_int_prod >= 0 && int_prod[ptr_int_prod] == 0)
    {
        ptr_int_prod--;
        len_prod--;
    }
    
    if (ptr_int_prod < 0)
    {
        product[0] = '0';
        product[1] = '\0';
        return;
	}
	
    ptr_prod = 0;
    
	while (ptr_int_prod >= 0)
    {
	    product[ptr_prod++] = (char)(int_prod[ptr_int_prod--] + '0');
	}
	product[ptr_prod] = '\0';
}

int main()
{
    char a[1005] = { 0 };
    char b[1005] = { 0 };
    int len_a, len_b;
    
 	while (scanf("%s %s",a,b)!=EOF)
	{
	    char product[2005] = { 0 };
	    len_a = (int)strlen(a);
	    len_b = (int)strlen(b);
	    multiply(a, len_a, b, len_b, product);
	    printf("%s\n", product);
	    char a[1005]={0};
	    char b[1005]={0};
	}
    return 0;
}
