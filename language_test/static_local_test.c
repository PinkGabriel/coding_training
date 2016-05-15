#include<stdio.h>  

static int q[10] = {1,2};

void test()
{
//	static char a[10];
	//static char a[10] = "abcabc";
	static char a[10] = "\0";
	char b[10];
	printf("a: %s\n",a);
	printf("b: %s\n",b);
	static int c;
	int d;
	printf("&a: %d\n",a);
	printf("c: %d\n",c);
	printf("d: %d\n",d);
}

int main(void)  
{  
	char *p = 6295704;
	puts(p);
	puts("above");
	*p = 'x';
	puts(p);
	puts("above");
//	puts(ma);
	test();
	static char ma[10] = "abc";
	return 0;  
}

