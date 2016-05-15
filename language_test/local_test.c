#include<stdio.h>  

static int q[10] = {1,2};

void test()
{
/* //
   3213708128
	char *p = 3962129312;
	puts(p);
	puts("above");
// */
	static char b[10] = "abcabc";
	char a[10] = "abcabc";
	printf("a: %s\n",a);
	printf("static b: %s\n",b);
	printf("&a: %x\n",a);
	printf("&b: %x\n",b);
}

int main(void)  
{  
	//char *p = 3962129312;
	char *p;
	//*p = 'x';
	p = 6295688;
	puts(p);
	puts("above");
//	puts(ma);
	test();
	static char ma[10] = "abc";
	return 0;  
}

