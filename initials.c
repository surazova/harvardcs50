#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //changes lowercase to uppercase
    string s = get_string("First Name: ");
    // printf("after:  ");
    // for (int i = 0, n = strlen(s); i < n; i++)
    // {
    //     if (islower(s[i]))
    //     {
    //         printf("%c", toupper(s[i]));
    //     }
    //     else
    //     {
    //         printf("%c", s[i]);
    //     }
    // }
    // printf("\n");
    //WORKS to print one initial
    //TODO: print the last name, how to solve the space issue?
    printf("initial: %c\n", toupper(s[0]));

    //finds a space
    if(str[i] == '')
    {
        for(j=i; i < len; j++)
        {
            //putchar prints a single character
            putchar(str[j]);
        }
    }
}
