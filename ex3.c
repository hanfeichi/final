#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int judge(char *s);
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("The program needs at least one integer parameter to run!\n");
        return -1;
    }
    for (int m = 1, c = judge(argv[m]); m < argc; m++)
    {
        if (c == -1)
        {
            printf("The parameter has to be an integer format!\n");
            return -1;
        }
    }
    int min = atof(argv[1]);
    for (int i = 1; i < argc; i++)
    {
        if (atof(argv[i]) < min)
            min = atof(argv[i]);
    }
    printf("Min parameter is %d\n", min);
    return 0;
} 
int judge(char *s)
{
    int p = 0, q = strlen(s);
    while (p < q && isdigit(s[p]))
        p++;
    if (p == q)
        return 0;
    else 
        return -1;
}