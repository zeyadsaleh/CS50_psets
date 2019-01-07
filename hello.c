#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("what is your name?\n"); //get the user's name
    printf("hello, my friend %s \n", name); //say hello to the user
}
