#include<stdio.h>  

static int stack_dir;  

static void find_stack_direction (void)
{  
	static char *addr = NULL;	/* address of first `dummy', once known */  
	char dummy;			/* to get stack address */  
	if (addr == NULL) {		/* initial entry */  
		addr = &dummy;  
		find_stack_direction ();/* recurse once */  
	}
	else {				/* second entry */
		if (&dummy > addr)
			stack_dir = 1;	/* stack grew upward */  
		else  
			stack_dir = -1;	/* stack grew downward */  
	}
}  

void test()
{
	static char a[10] = "abcabc";
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
	char *p = 6295632;
	puts(p);
	puts("above");
	*p = 'x';
	puts(p);
	puts("above");
	test();
	find_stack_direction();
	if(stack_dir==1)  
		puts("stack grew upward");  
	else  
		puts("stack grew downward");  
	static char ma[10] = "abc";
	return 0;  
}

