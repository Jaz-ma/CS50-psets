#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    // checks if there's a correct amount of input arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    // calculates Key length and turns it to uppercase
    int n = strlen(argv[1]);
    for (int l = 0 ; l < n ; l++)
    {
        argv[1][l] = toupper(argv[1][l]);
    }
    // checks if Key is 26 characters long
    if (n != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    // this for loop goes through each character in the key for error handling
    for (int i = 0 ; i < n ; i++)
    {
        // checks if the character is alphabetic
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
        // this for loop checks for repeated characters
        for (int j = i + 1 ; j < n ; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }

        }
    }
    string key = argv[1];

    string input = get_string("plaintext:  ");
    // this for loop substitutes each input character
    for (int k = 0, len = strlen(input) ; k < len ; k++)
    {
        // checks if character is alphabetic to only change letters
        if (isalpha(input[k]))
        {
            if (islower(input[k]))
            {
                input[k] = tolower(key[((int) input[k]) - 97]);
            }
            else
            {
                input[k] = key[((int) input[k]) - 65];
            }
        }
    }
    printf("ciphertext: %s\n", input);
}
