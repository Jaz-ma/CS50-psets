#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // ask for text input
    string text = {get_string("Text: ")};

    //counting letters words and sentences
    float letter_count = count_letters(text);
    float word_count = count_words(text);
    float sentences_count = count_sentences(text);

    // counting the grade
    float L = (letter_count / word_count) * 100;
    float S = ((sentences_count / word_count) * 100);
    int X = round((0.0588 * L) - (0.296 * S) - 15.8);

    // printing the grade depening on the X
    if (X > 16)
    {
        printf("Grade 16+\n");
    }
    else if (X < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", X);
    }
}

int count_letters(string text)
{
    int n = strlen(text);
    int letters = 0;
    for (int i = 0 ; i < n ; i++)
    {
        // checking if the char is alphabetical
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string word)
{
    int n = strlen(word);
    int words = 1;
    for (int i = 0 ; i < n ; i++)
    {
        // checking if the char is a space
        if ((int)word[i] == 32)
        {
            words++;
        }
    }
    return words;
}
int count_sentences(string word)
{
    int n = strlen(word);
    int sentences = 0;
    for (int i = 0 ; i < n ; i++)
    {
        //checking if the char is a '?' or a '!' or a '.'
        if ((int)word[i] == 33 || (int)word[i] == 63 || (int)word[i] == 46)
        {
            sentences++;
        }
    }
    return sentences;
}