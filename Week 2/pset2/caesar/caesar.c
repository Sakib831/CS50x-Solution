#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

// Defineing the function
int is_valid(int arguments, string key[]);
void cipher(string text, int key);

int main(int argc, string argv[])
{
    int test = is_valid(argc, argv);

    // Check if test failed or not
    if (test)
    {
        return test;
    }

    // Prompt the user for plaintext
    string plaintext = get_string("plaintext:  ");
    int key = atoi(argv[1]);

    cipher(plaintext, key);
}

int is_valid(int arguments, string key[])
{
    // Check the number of argument
    if (arguments != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Run the loop on every character
    for (int i = 0; i < strlen(key[1]); i++)
    {
        // Check if the argument contain anytype of invalid character
        if (isalpha(key[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    return 0;
}

void cipher(string text, int key)
{
    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            int offset = 0;
            if (isupper(text[i]))
            {
                offset = 'A';
            }
            else
            {
                offset = 'a';
            }

            // Converting to the cipher text
            int ci = text[i] - offset;
            int pi = (ci + key) % 26;

            printf("%c", pi + offset);
        }
        else
        {
            // If the character isn't a alphabet, then print it without changing
            printf("%c", text[i]);
        }
    }
    printf("\n");
}