// Hangman Game.
#include <stdio.h>

int process(int n, char word[n], char wordHided[n], char letter);
void board(int n, char wordHided[n], int lives); // Prints the board on the terminal.

int main(void)
{
    char word[30], letter;
    int i = 0, n = 0, lives = 5, flag = 0, num = 0, right = 0;
    
    printf("\n██╗  ██╗ █████╗ ███╗   ██╗ ██████╗ ███╗   ███╗ █████╗ ███╗   ██╗\n██║  ██║██╔══██╗████╗  ██║██╔════╝ ████╗ ████║██╔══██╗████╗  ██║\n███████║███████║██╔██╗ ██║██║  ███╗██╔████╔██║███████║██╔██╗ ██║\n██╔══██║██╔══██║██║╚██╗██║██║   ██║██║╚██╔╝██║██╔══██║██║╚██╗██║\n██║  ██║██║  ██║██║ ╚████║╚██████╔╝██║ ╚═╝ ██║██║  ██║██║ ╚████║\n╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝\n");
    printf("\nEnter a phrase or word: \n"); // Prompt for user input
    fgets(word, 30, stdin);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    do // Loop to determine the size of the word.
    {
        if (word[i] != '\0')
        {
            n++;
        }
        i++;
    } while (word[i] != '\0');
    n--;

    char wordHided[n];
    for (i = 0; i < n; i++) // Copy the word to another array.
    {
        wordHided[i] = word[i];
    }
    for (i = 0; i < n; i++) // Replace characters with "_" to hide the word.
    {
        if (wordHided[i] != ' ')
        {
            wordHided[i] = '_';
        }
    }
    
    do // The game loop starts.
    {
        board(n, wordHided, lives);

        printf("\nEnter a letter: \n");
        scanf(" %c", &letter);

        flag = process(n, word, wordHided, letter);

        if (flag == 0) // The letter isn't in the word.
        {
            lives--;
            printf("\nYou failed!\n");
        }
        right = 0;
        for (i = 0; i < n; i++) // Count correct letters.
        {
            if (wordHided[i] == word[i])
            {
                right++;
            }
        }
        if (right == n) // If the number of correct letters equals the word length, the player guessed the word.
        {
            board(n, wordHided, lives);
            printf("\n██╗   ██╗ ██████╗ ██╗   ██╗    ██╗    ██╗██╗███╗   ██╗\n╚██╗ ██╔╝██╔═══██╗██║   ██║    ██║    ██║██║████╗  ██║\n ╚████╔╝ ██║   ██║██║   ██║    ██║ █╗ ██║██║██╔██╗ ██║\n  ╚██╔╝  ██║   ██║██║   ██║    ██║███╗██║██║██║╚██╗██║\n   ██║   ╚██████╔╝╚██████╔╝    ╚███╔███╔╝██║██║ ╚████║\n   ╚═╝    ╚═════╝  ╚═════╝      ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝\n");
            printf("\nYou guessed the word!\n");
            break;
        }
    } while (lives != 0); // Ends when all 5 lives are used.
    if (lives == 0) // Print the phrase when lives finish.
    {
        printf("\n██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗\n██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗\n██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝\n██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗\n╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║\n ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\n\n\n");
        printf("\nThe phrase was: %s\n", word);
    }
    return 0;
}

int process(int n, char word[n], char wordHided[n], char letter) // Checks if the letter is in the word.
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (word[i] == letter)
        {
            wordHided[i] = letter;
            flag = 1;
        }
    }
    return flag;
}

void board(int n, char wordHided[n], int lives) // Prints the board.
{
    printf("\n\n\n██╗  ██╗ █████╗ ███╗   ██╗ ██████╗ ███╗   ███╗ █████╗ ███╗   ██╗\n██║  ██║██╔══██╗████╗  ██║██╔════╝ ████╗ ████║██╔══██╗████╗  ██║\n███████║███████║██╔██╗ ██║██║  ███╗██╔████╔██║███████║██╔██╗ ██║\n██╔══██║██╔══██║██║╚██╗██║██║   ██║██║╚██╔╝██║██╔══██║██║╚██╗██║\n██║  ██║██║  ██║██║ ╚████║╚██████╔╝██║ ╚═╝ ██║██║  ██║██║ ╚████║\n╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝\n");
    printf("%d lives\n", lives);
    for (int i = 0; i < n; i++)
    {
        printf("%c ", wordHided[i]);
    }
}