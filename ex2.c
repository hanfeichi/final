#include <stdio.h>
#define MAXLINE 50
#undef reverse
char reverse(char a[MAXLINE], int end, int start);
int main()
{
    char a[MAXLINE];
    int i = 0;
    for (i = 0; (a[i] = getchar()) != EOF && a[i] != '\n'; i++)
        ;
    reverse(a, i - 1, 0);
    printf("%s", a);
    return 0;
}
char reverse(char a[MAXLINE], int end, int start)
{
    if (end - start < 1)
    {
        return 0;
    }
    else
    {
        char temp;
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
        reverse(a, end, start);
        return 0;
    }
}