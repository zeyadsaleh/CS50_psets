#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[]) //get the result from the commandline argument
{    
    if (argc != 2)   //if the commandline argument is not just 2 words 
    {
        printf("Usage: ./vignere keyword\n"); 
        return 1;
    }
    else 
    {
        for (int x = 0; x < strlen(argv[1]); x++) // check if the all the letters in the keyword are alphabetic
        {
            if (isalpha(argv[1][x]))
            {
                if (x == strlen(argv[1]) - 1)
                {
                    string plaintext = get_string("plaintext: ");//prompt the plaintext from the user
                    printf("ciphertext: ");
                    int g = 0;
                    for (int i = 0, n = strlen(plaintext); i < n; i++)
                    {                        
                        if (isalpha(plaintext[i])) //see if the plaintext is alphabetic 
                        { 
                            int key;
                            int key_pos = g % (strlen(argv[1]));
                            if (isupper(plaintext[i])) //see if the character is uppercase letter
                            {
                                if (isupper(argv[1][key_pos]))
                                {
                                    key = (argv[1][key_pos] - 65) % 26;
                                }
                                else
                                {
                                   key = (argv[1][key_pos] - 97) % 26;
                                }
                                printf("%c", (((plaintext[i] - 65) + key) % 26) + 65); //shift plaincase character by keyword
                                g++;    
                            }
                            else  //see if the character is lowecase letter
                            {
                                 if (isupper(argv[1][key_pos]))
                                {
                                    key = (argv[1][key_pos] - 65) % 26;
                                }
                                else
                                {
                                   key = (argv[1][key_pos] - 97) % 26;
                                }
                                printf("%c", (((plaintext[i] - 97) + key) % 26) + 97); //shift plaincase character by keyword
                                g++; 
                            }
                        }   
                        else
                        {
                            printf("%c", plaintext[i]); // if the plaintext is not alphabetic leave is as it is
                        }
                    }       
                }
            } 
            else
            {
                printf("Usage: ./vigenere keyword \n");
                return 1;
                break;
            }
        }
        printf("\n"); 
    }
    return 0;
}

