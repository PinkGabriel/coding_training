#include<stdio.h>

int main()
{
	/*
	freopen("input", "r", stdin);
	char name[10], school[10];
	int age;
	while (scanf("%s%d%s", name, &age, school) != EOF) {
		printf("name: %s, age: %d, school: %s\n", name, age, school);
	}
	*/
	//freopen("input.txt", "r", stdin);
	char s1[10] = {'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y'};
	char s2[10] = {'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y'};
	char s3[10] = {'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y'};
	char *fmt1 = "%5c";
	//char *line = "%[^\n]%*c";
	char *fmt2 = "%[^x]";
	char *fmt3 = "%[a-x]";
	//scanf(fmt1, s1);
	printf("s1:%s\n", s1);
	if (scanf(fmt2, s2) == 0)
		printf("s2:%s\n", s2);
	scanf(fmt3, s3);
	printf("s3:%s\n", s3);
	return 0;
}
