#include <stdio.h>

int main()
{
    for(int i = 1; i <= 10; i++)
    {
        printf("The table of %d is: \n", i);
        int j;
        for(j = 1; j <= 10; j++)
        {
            printf("%d x %d = %d\n", i, j, i*j);
        }
    }

    return 0;
}
