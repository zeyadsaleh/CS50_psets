#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[]) //get the result from the commandline argument
{    
    if (argc != 2)   //if the commandline argument is not just 2 words
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]); //turn key into integer
        if (key != 0)
        {
            string plaintext = get_string("plaintext: ");//prompt the plaintext from the user
            printf("ciphertext: ");
            for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                if (isalpha(plaintext[i])) //see if the plaintext is alphabetic 
                {
                    if (isupper(plaintext[i])) //see if the character is uppercase letter
                    {
                        printf("%c", (((plaintext[i] - 65) + key) % 26) + 65); //shift plaincase character by key
                    }
                    else if (islower(plaintext[i])) //see if the character is lowecase letter
                    {
                        printf("%c", (((plaintext[i] - 97) + key) % 26) + 97); //shift plaincase character by key
                    }
                }             
                else
                {
                    printf("%c", plaintext[i]); // if the plaintext is not alphabetic leave is as it is
                }
            }
            printf("\n");
        }
        else //if the key is not integer
        {
            printf("Usage: ./caesar key\n"); 
        }
    } 
    return 0;
}
