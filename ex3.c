#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("The program needs at least one integer parameter to run!\n");
        return -1;
    }
    if (!isdigit(argv[1]))
    {
        printf("The parameter has to be an integer format!\n");
        return -1;
    }
    int min;
    min = atof(argv[1]);
    for (int i = 1; i < argc; i++)
    {
        if (!isdigit(argv[i]))
        {
            printf("The parameter has to be an integer format!\n");
            return -1;
        }
        if (atof(argv[i]) < min)
            min = atof(argv[i]);
    }
    printf("Min parameter is %d\n", min);
    return 0;
}