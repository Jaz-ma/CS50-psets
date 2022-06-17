#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    // compares score 1 to score 2
    if (score1 > score2)
    {
        printf("Player 1 wins! \n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins! \n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // gets the length of the word provided
    int n = strlen(word);
    // intializes the score variable
    int score = 0;
    for (int i = 0 ; i < n ; i++)
    {
        // checks if the char is alphabetical (could have used isalpha() function here)
        if (((int) word[i] >= 65 && (int) word[i] <= 90) || ((int) word[i] >= 97 && (int) word[i] <= 122))
        {
            //checks if word is lowercase, if so, convert to uppercase
            if (islower(word[i]))
            {
                word[i] = toupper(word[i]);
            }
            // grabs the corresponding character point from the POINTS array and adds it to the score variable
            score += POINTS[(word[i] - 65)];
        }
    }
    return score;
}
