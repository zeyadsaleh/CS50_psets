#include <cs50.h>
#include <stdio.h>

int main(void)
{
int n;
    do // prompt the user for input
    {
        n=get_int("Hight= "); // chech the value is valid
    }
    while (n<1 || n>8);
    
    for (int i=0; i<n; i++) // printing new line
    {
        for (int j = 0; j<n-i; j++) //printing the spaces 
        {
            printf(" ");
        }
        for (int x = 0; x<i+1; x++) //printing the hashes
        {
            printf("#");
        }
        printf("\n");
    }
    
}
    

