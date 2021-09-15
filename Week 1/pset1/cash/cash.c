#include <math.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for owed money
    float owed;
    do
    {
        owed = get_float("Owed Money: ");
    }
    while (owed < 0);

    // Round the owed value
    int cents = round(owed * 100);
    int coins = 0;

    // Calculating the number of coins
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
        }
        else if (cents >= 10)
        {
            cents -= 10;
        }
        else if (cents >= 5)
        {
            cents -= 5;
        }
        else
        {
            cents--;
        }
        coins++;
    }

    // Display the number of coins
    printf("Coins %i\n", coins);
}