#include<stdio.h>
#include<string.h>
int xstrlen(char *);
int xstrcpy(char *,char *);
int xstrcat(char *,char *);
int main()
{
	char s1[20]="hii";
	char s2[20]="hello";
	char s3[20];
	char s4[20];
	int l1,l2;
	l1=xstrlen(s1);
	printf("length of %s is %d :\n ",s1,l1);
	//l2=strlen(s2);
	l2=xstrlen(s2);
	printf("length of %s is %d :\n ",s2,l2);

	xstrcpy(s3,s1);
	printf("destination string is %s\n",s3);

	xstrcat(s1,s2);
	printf("concatination : %s\n",s1,s2);
return 0;
}
int xstrlen(char *x)
{
	int len=0;
	while(*x!='\0')
	{
		len++;
		x++;

	}
	return(len);
}
int xstrcpy(char *d,char *s)
{
	while(*s!='\0')
	{
		*d=*s;
		s++;
		d++;
	}
}
int xstrcat(char *m1,char *m2)
{
	for(*m2=3;*m2!='\0'; )
	{

		*m1=*m2;
		m2++;
		m1++;
	}
}
