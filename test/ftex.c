#include<stdio.h>
int main()
{
        char s[50], *fmt = "%[^\n]%*c";
        freopen("input.txt", "r", stdin);
        while (scanf(fmt, s) != EOF) {
                printf("%s\n", s); 
        }   
        return 0;
}
