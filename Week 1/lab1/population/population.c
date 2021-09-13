#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt the user for start size
    int start_size;
    do
    {
        start_size = get_int("Start Size: ");
    }
    while (start_size < 9);

    // Prompt the user for end size
    int end_size;
    do
    {
        end_size = get_int("End Size: ");
    }
    while (end_size < start_size);

    // Calculate the number of years
    int years = 0;
    int population = start_size;

    while (end_size > population)
    {
        population = population + (population / 3) - (population / 4);
        years++;
    }
    printf("Years: %i\n", years);
}