#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // gets input from user
    int answer = get_int("Height: ");
    // asks for input again if it's not between 1 and 8
    while (answer < 1 || answer > 8)
    {
        answer = get_int("Height: ");
    }
    // the for loop prints each level of the pyramid
    for (int i = 1 ; i < answer + 1; i++)
    {
        // this for loop prints the left side spaces
        for (int j = 0; j < answer - i; j++)
        {
            printf(" ");
        }
        // this for loop prints the left side hashes
        for (int k = 0 ; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
        
        // this for loop prints the right side hashes
        for (int m = 0; m < i; m++)
        {
            printf("#");
        }
        printf("\n");
    }

}