#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int count;
    int coins;
    float dollars;
    do //prompting  the user for valid input
    {
        dollars=get_float("Change: "); 
    }
    while(dollars<0);
    
    dollars=dollars*100; //rounding the dollars
    coins=dollars; //convert the float into integer
    
    count=0;
 
    while(coins>=25) // use the largest coin possible
    {   
       coins=coins-25;
        count=count+1;
    }
    while(coins>=10)
    {
        coins=coins-10;
        count=count+1;
    }
    while(coins>=5)
    {
       coins=coins-5;
        count=count+1;
    }
    while(coins>=1)
    {
        coins=coins-1;
        count=count+1;
    }
    printf("%i\n",count);
 
}

