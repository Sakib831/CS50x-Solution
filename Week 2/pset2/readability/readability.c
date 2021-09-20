#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int letter_count(string text);
int word_count(string text);
int sentence_count(string text);
int calculate_grade(int letters, int words, int sentences);

int main(void)
{
    // Prompt the user for input
    string text = get_string("Text: ");

    // Assigning the function values
    int letter = letter_count(text);
    int word = word_count(text);
    int sentence = sentence_count(text);
    int grade = calculate_grade(letter, word, sentence);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int letter_count(string text)
{
    int letter = 0;

    // Run the loop until is equal to the text
    for (int i = 0; i < strlen(text); i++)
    {
        // Check if the current index is an alphabet or not
        if (isalpha(text[i]))
        {
            letter++;
        }
    }
    return letter;
}

int word_count(string text)
{
    int word = 0;

    // Run the loop until is equal to the text
    for (int i = 0; i < strlen(text); i++)
    {
        // Check if the index is a White-Space
        if (text[i] == ' ')
        {
            word++;
        }
    }
    return ++word;
}

int sentence_count(string text)
{
    int sentence = 0;

    // Run the loop until is equal to the text
    for (int i = 0; i < strlen(text); i++)
    {
        // Check if the index is '.' or '!' or '?'
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence++;
        }
    }
    return sentence;
}

int calculate_grade(int letters, int words, int sentences)
{
    // Assigning variables
    float words_per_100 = words / 100.0;
    float l = letters / words_per_100;
    float s = sentences / words_per_100;

    // Calculate the grade & round it
    int grade = round(0.0588 * l - 0.296 * s - 15.8);
    return grade;
}