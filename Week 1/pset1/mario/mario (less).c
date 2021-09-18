#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    int space = height;

    // Drawing the mario blocks
    for (int i = 1; i <= height; i++)
    {
        // Print the spaces
        for (int p = space; p > 1; p--)
        {
            printf(" ");
        }

        // Print the pounds or blocks
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        space--;
        printf("\n");
    }
}