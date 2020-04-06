#include<stdio.h>
#define ALPHABET(ch) ((ch>=97 && ch<=122) || (ch>=65 && ch<=90))
int main()
{
	char ch;
	printf("Enter any character : ");
	scanf("%c",&ch);
	if ALPHABET(ch)
	   printf("%c is Alphabet\n",ch);
	else
	   printf("%c is not Alphabet\n",ch);
	return 0;
}
