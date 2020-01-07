#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100
char getdouble(double *pn);
int main()
{
    int t;
    double s[MAXLINE];
    double sum = 0,sum0;
    for (t = 0; t < MAXLINE; t++)
    {
        if (getdouble(&s[t]) == '\n')
        {
            sum = sum + s[t];
            break;
        }
        sum = sum + s[t];
    }
    sum0=sum*sum;
    printf("%.2f\n", sum0);
    return 0;
}
int getch(void);
void ungetch(int);
char getdouble(double *pn)
{
    char c;
    int sign, doublebit = 1;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.')
    {
        c = getch();
        if (!isdigit(c) && c != EOF && c != '+' && c != '-')
        {
            ungetch(c);
            return 0;
        }
        else
        {
            for (; isdigit(c); c = getch())
            {
                *pn = 10 * *pn + (c - '0');
                doublebit = doublebit * 10;
            }
        }
    }
    *pn = *pn / doublebit * sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch:too many characters\n");
    else
        buf[bufp++] = c;
}