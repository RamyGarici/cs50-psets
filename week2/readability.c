#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
float calculate_grade(int letters, int words, int sentences);
int count_sentences(string text);

int main(void)
{
    string text = "";
    while (strlen(text) == 0)
    {
        text = get_string("Text:");
    }
    int text_length = strlen(text);
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float index = calculate_grade(letters, words, sentences);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}

int count_letters(string text)
{
    int count_letters = 0;
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(text[i]))
        {
            count_letters++;
        }
    }
    return count_letters;
}

int count_words(string text)
{
    int count_words = 1;
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == ' ')
        {
            count_words++;
        }
    }
    return count_words;
}
int count_sentences(string text)
{
    int count = 0;
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}

float calculate_grade(int letters, int words, int sentences)
{
    float index;
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}
