#include <cs50.h>
#include <stdio.h>

int luhn(long number)
{
    int numbers = 0;
    int other = 0;
    int d = 0;
    int digit;
    long number_copy = number;
    while (number_copy > 0)
    {
        numbers += number_copy % 10;
        number_copy = number_copy / 10;
        number_copy = number_copy / 10;
    }
    number_copy = number;

    while (number_copy > 0)
    {
        number_copy = number_copy / 10;
        digit = 0;
        d = 0;
        digit = number_copy % 10;
        digit *= 2;
        if (digit >= 10)
        {
            d = digit % 10;
            digit = digit / 10;
            d += digit;
            digit = d;
        }

        other += digit;
        number_copy = number_copy / 10;
    }
    int final_sum = numbers + other;

    if (final_sum % 10 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(void)
{
    long number = get_long("Number: ");
    int valid;
    int len = 0;
    int first_two_digits = 0;
    valid = luhn(number);
    while (number > 0)
    {
        if (number < 100 && number > 9)
        {
            first_two_digits = number;
        }
        number /= 10;
        len++;
    }

    if (valid == 0)
    {
        if (len == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            printf("AMEX\n");
        }
        else if (first_two_digits > 50 && first_two_digits < 56 && len == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (first_two_digits / 10 == 4 && (len == 16 || len == 13))
        {
            printf("VISA\n");
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
