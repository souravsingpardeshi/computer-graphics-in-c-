#include<stdio.h>
#define UPPER(ch) (ch>=65 && ch<=90)
int main()
{
	char ch;
	printf("Enter any character : ");
	scanf("%c",&ch);
	if UPPER(ch)
	{
	   printf("%c is upper case\n",ch);
	 }
	else
	   printf(" %c is not upper case\n",ch);
	return 0;
}
