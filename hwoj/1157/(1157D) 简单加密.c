#include <stdio.h>
int main()
{
	char x;
	while ((x=getchar())!=EOF)
	{
		x=x-'\0';
		if(x!='\n')
	{		
		if(x<57&&x>=48)//Êý×Ö 
		{
			x=x+1;
			printf("%c\n",x);
		}
		
		else if(x==57)
		{
			x=48;
			printf("%c\n",x);
		}
		
		else if(x<=90&&x>=65)//´óÐ´
		{
			x=x+32;
			printf("%c\n",x);
		}
		else if(x>=97&&x<=122)//Ð¡Ð´
		{
			x=x-32; 
			printf("%c\n",x);
		}
		else
		{
			printf("%d\n",x);
		}
	}
	}
	return 0;
}
