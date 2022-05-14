#include <cs50.h>
#include <stdio.h>

long get_ccnum(void);
int num_len(long num);
bool is_lenv(int cc_len);
int get_digits1(long user_cc);
int get_digits2(long user_cc);
bool is_sumv(int sum1, int sum2);
string card_type(long user_cc);

int main(void)
{
    // Get credit card number.
    long user_cc = get_ccnum();
    // Get validation inputs.
    int cc_len = num_len(user_cc);
    bool len_validation = is_lenv(cc_len);
    int sum1 = get_digits1(user_cc);
    int sum2 = get_digits2(user_cc);
    bool sum_validation = is_sumv(sum1, sum2);
    // Start Validation.
    if (len_validation)
    {
        if (sum_validation)
        {
            printf("%s\n", card_type(user_cc)); // Return card type.
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

// Get the credit card number from the user.
long get_ccnum(void)
{
    long ccnum;
    do
    {
        ccnum = get_long("Number: ");
    }
    while (ccnum < 0);
    return ccnum;
}

// Return the length of numbers.
int num_len(long num)
{
    int i = 0;
    while (num != 0)
    {
        num = num / 10;
        i++;
    }
    return i;
}

// Checks if the credit card number is a valid length.
bool is_lenv(int cc_len)
{
    if (cc_len < 13 || cc_len > 16 || cc_len == 14)
    {
        return false;
    }
    return true;
}
 
// Sum every other digit starting with the last digit.
int get_digits1(long user_cc)
{
    long digits;
    int sum;
    for (digits = user_cc, sum = 0; digits > 0; digits /= 100)
    {
        sum += digits % 10;
    }
    return sum;
}

/*  Double every other digit starting with the second to last digit
 *  and then return the sum of the digits of those products. */
int get_digits2(long user_cc)
{
    long digits;
    int prod_sum;
    for (digits = user_cc / 10, prod_sum = 0; digits > 0; digits /= 100)
    {
        // If product is a 2 digits then split it up and add the seperate digits.
        if (2 * (digits % 10) >= 10)
        {
            prod_sum += (2 * (digits % 10)) / 10;
            prod_sum += (2 * (digits % 10)) % 10;
        }
        else
        {
            prod_sum += (2 * (digits % 10)) % 10;
        }
    }
    return prod_sum;
}

// Validates the last digit of the sum is 0.
bool is_sumv(int sum1, int sum2)
{
    int sum = sum1 + sum2;
    if (sum % 10 != 0)
    {
        return false;
    }
    return true;
}

// Returns the type of card.
string card_type(long user_cc)
{
    if (user_cc / 10000000000000 == 34 || user_cc / 10000000000000 == 37)
    {
        return "AMEX";
    }
    else if (user_cc / 100000000000000 >= 51 && user_cc / 100000000000000 <= 55) 
    {
        return "MASTERCARD";
    }
    else if (user_cc / 1000000000000000 == 4 || user_cc / 1000000000000 == 4)
    {
        return "VISA";
    }
    return "INVALID";
}
