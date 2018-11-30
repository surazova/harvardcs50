#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX16 5599999999999999
#define MIN16 4000000000000000

#define MAX15 379999999999999
#define MIN15 340000000000000

#define MAX13 4999999999999
#define MIN13 4000000000000

#define VISAFIRST 4
#define MASTERCARDFIRST 5
#define MASTERCARDSECONDMIN 1
#define MASTERCARDSECONDMAX 5
#define AMEXFIRST 3
//#define AMEXSECOND secondDigit == 4 || secondDigit == 7

int main(void)
{
    long long ccnum = get_long_long("Number: ");
    int length = 0;
    int modifier = 0;
    if (ccnum >= MIN16 && ccnum <= MAX16)
    {  //Add modifier for even, 16 digit number
        length = 16;
        modifier = 1;
    }
    else if (ccnum >= MIN15 && ccnum <= MAX15)
    {
        length = 15;
    }
    else if (ccnum >= MIN13 && ccnum <= MAX13)
    {
        length = 13;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
    int timesTwo = 0;
    int noTimes = 0;
    int firstDigit = 0;
    int secondDigit = 0;

    for (; length > 0; length--)
    {
        int digit = ccnum % 10;
        // printf("length: %i\tDigit: %i\n", length, digit);
        if (length == 2)
        {
            secondDigit = digit;
        }
        else if (length == 1)
        {
            firstDigit = digit;
        }

        ccnum = ccnum / 10;
        if (length % 2 == 0) {
            int temp = digit * 2;
            timesTwo += temp / 10 + temp % 10;
        }
        else
        {
            noTimes += digit;
        }
    }
    // printf("timesTwo: %i\tnoTimes: %i\n", timesTwo, noTimes);
    int final = noTimes + timesTwo;
    if (final % 10 == 0)
    {
        if (firstDigit == 4)
        {
            printf("VISA\n");
        }
        else if (firstDigit == 5 || (secondDigit >= 1 && secondDigit <= 5))
        {
            printf("MASTERCARD\n");
        }
        else if (firstDigit == 3 && (secondDigit == 4 || secondDigit == 7))
        {
            printf("AMEX\n");
        }
        else
        {
        printf("INVALID\n");
        }
}
}

//Mastercard: 5555555555554444
//Amex: 378282246310005

//Another solution
// else if (firstDigit == AMEXFIRST && AMEXSECOND)
//         {
//             printf("AMEX\n");
//         }
// else if(fistDigit == MASETERCARDFIRSˇ)
//  {
//      if(secondDigit >= MASTERCARDSECONDMIN && secondDigit)
//  }