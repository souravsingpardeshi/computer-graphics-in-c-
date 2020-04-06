#include<stdio.h>
#define LOWER(ch) (ch>=97 && ch<=122)
int main()
{
	char ch;
	printf("Enter any character : ");
	scanf("%c",&ch);
	if LOWER(ch)
	   printf("%c is lower case\n",ch);
	else
	   printf("%c is not lower case\n",ch);
	return 0;
}
