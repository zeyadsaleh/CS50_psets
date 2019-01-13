#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; //prompting the user for input
    do
    {
        n = get_int("Hight= "); // check if the input is valid
    }
    while (n < 1 || n > 8);
    for (int i = 0; i < n; i++) // for new line
    {
        for (int j = 0; j < n - (i + 1); j++) // for the spaces of the left pyramid
        {
            printf(" ");
        }
        for (int x = 0; x < i + 1; x++) // for the hashes in the left pyramid
        {
            printf("#");
        }
        printf("  ");
        for (int z = 0; z < i + 1; z++) // for the hashes of the right pyramid
        {
            printf("#");
        }
        printf("\n");
    }
}
