#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cc_number, cc_number1, cc_number2, cc_number3;
    int first_2_digits, first_digit; 
    int last_num, sec_to_last_num, sum, digit, num_of_digits = 0;
    
    do //prompting the credit card number from the user
    {
        cc_number = get_long("Number: ");
    }
    while (cc_number < 0);
    
    cc_number1 = cc_number;
    cc_number2 = cc_number;
    cc_number3 = cc_number;
    
    while (cc_number) //make the checksum of the card number
    {
        last_num = cc_number % 10;
        sum = sum + last_num;
        cc_number = cc_number / 10;
        sec_to_last_num = cc_number % 10;
        sec_to_last_num = sec_to_last_num * 2;
        digit = sec_to_last_num % 10;
        sec_to_last_num = sec_to_last_num / 10;
        sec_to_last_num = sec_to_last_num + digit;
        sum = sum + sec_to_last_num;
        cc_number = cc_number / 10;
    }
    
    while (cc_number1 != 0) // count the number of digits 
    {
       cc_number1 = cc_number1 / 10;
       num_of_digits++;
    }
    
    while (cc_number2 >= 100) // find the first 2 digits
    {
       cc_number2 = cc_number2 / 10;
       first_2_digits = cc_number2;
    }
    
    while (cc_number3 >= 10) // find the first digit
    {
       cc_number3 = cc_number3 / 10;
       first_digit = cc_number3;
    }

    if (sum % 10 == 0) //check if the card is valid or invalid
    {
        if (num_of_digits == 15 && (first_2_digits == 34 || first_2_digits == 37)) //find the      company
        {
            printf("AMEX\n");
        }
            else if (num_of_digits == 16 && (first_2_digits == 51 || first_2_digits == 52 ||        first_2_digits == 53 || first_2_digits == 54 || first_2_digits == 55))
        {
            printf("MasterCard\n");
        }
        else if ((num_of_digits == 13 || num_of_digits == 16) && first_digit == 4)
        {
            printf("VISA\n");
        }
    }
    
    else
    {
        printf("INVALID\n");
    }
}

