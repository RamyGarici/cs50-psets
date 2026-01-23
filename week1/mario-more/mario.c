#include <cs50.h>
#include <stdio.h>

void build(int n)
{

    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main(void)
{
    int n;
    do
    {
        n = get_int("What size will your pyramid be? (positive size) ");
    }
    while (n < 1 || n > 8);
    build(n);
}
