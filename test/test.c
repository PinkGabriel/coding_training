#include<stdio.h>

int main()
{
	freopen("a", "r", stdin);
	char c, n;
	n = '\n';
	printf("newline is: %d\n", n);
	while ((c = getchar()) != EOF)
		printf("%d\n", c);
	return 0;
}
