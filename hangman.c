#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "words.c"
void delete_buffer()
{
    while (getchar() != '\n');
}
int main()
{
    srand(time(NULL));
    int word_index = rand() % WORDS_LENGTH;

    char word[50];
    strcpy(word, words[word_index]);

    int word_length = strlen(word);

    int word_spaces_length = 2*word_length - 1;
    char word_spaces[word_spaces_length + 1]; // added 1 because of the null terminator
    for(int i = 0; i < word_spaces_length; i++)
    {
        word_spaces[i] = '#';
    }
    word_spaces[word_spaces_length] = '\0';
    for (int i = 0; i < word_spaces_length; i +=2)
    {
        word_spaces[i] = '_';
        if (i+1 < word_spaces_length)
        {
            word_spaces[i+1] = ',';
        }
    }
    int number_of_guessed_characters = 0;
    do
    {
        printf("The guessed word: %s", word_spaces);
        printf("\n");

        char user_guess, newline;
        printf("Guess a letter: ");
        int checker = scanf("%c%c", &user_guess, &newline);
        if (checker != 2 || newline != '\n')
        {
            delete_buffer();
            continue;
        }

        int correct_char_indicator = 0;
        for (int i = 0; i < word_length; i ++)
        {
            if (user_guess == word[i])
            {
                correct_char_indicator = 1;
                word_spaces[i*2] = user_guess;
                word[i] = '#';
                number_of_guessed_characters += 1;
                break;
            }

        }
        if (correct_char_indicator == 1)
        {
            printf("\nNice :)\n");
        }
        else
        {
            printf("\nWrong!\n");
        }
    }
    while (number_of_guessed_characters < word_length);
    if (number_of_guessed_characters == word_length)
    {
        printf("The guessed word: %s\n", word_spaces);
        printf("Congratulations!!! you guessed the word right :)\n");
        printf("PRESS ENTER TO EXIT..");
        char temp[2];
        fgets(temp, 2, stdin);
    }
    return 0;

}
