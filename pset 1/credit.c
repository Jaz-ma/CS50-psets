#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long card_num;
    long digit_num;
    card_num = get_long("Number: ");
    digit_num = 0;
    long n = card_num;
    // this do while loop counts the number of digits of the number
    do
    {
        n /= 10;
        digit_num++;

    }
    while (n != 0);
    //intializing variables for the checksum
    long doubled_digit;
    long regular_digit;
    long products;
    long remainders = 0;
    long products_digits = 0;
    long checksum = 0;
    // this for loop counts the checksum
    for (int i = 0 ; i < 1 + (digit_num / 2) ; i++)
    {
        regular_digit = floor(card_num / pow(10, (i * 2)));
        doubled_digit = floor(card_num / pow(10, 1 + (i * 2))) ;
        remainders += regular_digit % 10;
        products = (doubled_digit % 10) * 2 ;
        if (products >= 10)
        {
            products_digits += (products % 10) + (floor(products / 10));
        }
        else
        {
            products_digits += products;
        }
        checksum = (products_digits + remainders);
    }
    // this if function checks conditions and outputs accordinglly
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
    }
    // checks if the number of digits corresponds with any of the given
    else if (digit_num == 16 || digit_num == 13 || digit_num == 15)
    {
        // checks if its a visa card
        if ((floor(card_num / (pow(10, digit_num - 1))) == 4) && (digit_num == 13 || digit_num == 16))
        {
            printf("VISA\n");
        }
        //checks if its an American Express card
        else if ((floor(card_num / (pow(10, digit_num - 2))) == 34) || (floor(card_num / (pow(10, digit_num - 2))) == 37))
        {
            printf("AMEX\n");
        }
        //checks if its a MASTERCARD card
        else if ((floor(card_num / (pow(10, digit_num - 2))) >= 51) && (floor(card_num / (pow(10, digit_num - 2))) <= 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}