#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"
#include "generic_vector.h"
#include "avl_tree.h"
#include "generic.h"

#define SIZE 30

void read_dictionary(GENERIC_VECTOR set_of_words[]);

GENERIC_VECTOR* skim_dictionary(void);

Boolean continue_prompt(void);

Boolean game_prompt(void);

int word_length_prompt(void);

int guesses_prompt(void);

char guess_letter(void);

void clear_keyboard(void);

void get_total(int word_length, GENERIC_VECTOR set_of_words[]);

Boolean running_total_prompt(void);

void hangman(void);

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess);

int main(int argc, char* argv[])
{
GENERIC_VECTOR set_of_words[30];

int i;


for (i = 0; i < 30; i++)
{
    set_of_words[i] = NULL;
}


for (i = 0; i < 30; i++)
{
    set_of_words[i] = generic_vector_init_default(my_string_init_copy, my_string_destroy);

    if (set_of_words[i] == NULL)
    {
        printf("Unable to create a generic vector\n");
        exit(1);
    }
}



read_dictionary(set_of_words);


//THIS IS CHECKPOINT 1 for lab 7


/*for (i = 0; i < 30; i++)
{
        printf("[%d]: %d\n", i, generic_vector_get_size(set_of_words[i]));

}*/




for (i = 0; i < 30; i++)
{
    generic_vector_destroy(&set_of_words[i]);
}


hangman();
return 0;
}
Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
    int i;

    while (my_string_pop_back(new_key));


    for (i = 0; i < my_string_get_size(word); i++)
    {
        if (*my_string_at(word, i) == guess)
        {
            if (!my_string_push_back(new_key, guess))
            {
                return FAILURE;
            }
        }
        else
        {
            if (!my_string_push_back(new_key, *my_string_at(current_word_family, i)))
            {
                return FAILURE;
            }
        }
    }
    return SUCCESS;
}

void hangman()
{

    MY_STRING* dictionary = skim_dictionary();

    GENERIC_VECTOR largest_family = NULL;

    TREE hTree = avl_tree_init_default();

    MY_STRING word_key = my_string_init_default();

    MY_STRING guess_list = my_string_init_c_string(" ");

    MY_STRING word_family = my_string_init_default();

    int word_length, guess_count, i;
    char running_total, current_guess;




    if (game_prompt())
    {
        word_length = word_length_prompt();

    
        GENERIC_VECTOR set_of_words[word_length];


        guess_count = guesses_prompt();


        running_total = running_total_prompt();

        for (i = 0; i < word_length; i++)
        {
            my_string_push_back(word_key, '-');
        }



        do
        {

            printf("\n\n\n------------------------------------\n");

            printf("The word is %d letters long.\n", word_length);

            printf("The amount of guesses selected is %d.\n", guess_count);

            printf("------------------------------------\n\n\n");
            do
            {
                printf("You have %d guess(es) remaining!\nLetters guessed: ", guess_count);

                my_string_insertion(guess_list, stdout);
                printf("\nCurrent word: ");
                my_string_insertion(word_key, stdout);
                printf("\n");
                do
                {
                    current_guess = guess_letter();

                } while (check_if_used(guess_list, current_guess));

                my_string_push_back(guess_list, current_guess);

                my_string_push_back(guess_list, ',');

                my_string_push_back(guess_list, ' ');

                if (running_total)
                {
                    printf("Total words remaining:\n");
                    get_total(word_length, set_of_words[word_length]);
                }

                for (i = 0; i < generic_vector_get_size(dictionary[word_length]); i++)
                {
                    get_word_key_value(word_key, word_family, generic_vector_at(dictionary[word_length], i), current_guess);


                    avl_tree_push_back(hTree, word_family, my_string_at(dictionary[word_length], 0));
                }


                largest_family = avl_tree_get_largest_family(hTree, running_total);

                generic_vector_destroy(&(dictionary[word_length]));
                dictionary[word_length] = generic_vector_init_default(my_string_init_copy, my_string_destroy);

                for (i = 0; i < generic_vector_get_size(largest_family); i++)
                {
                    generic_vector_push_back(dictionary[word_length], generic_vector_at(largest_family, i));
                }

                get_word_key_value(word_key, word_family, generic_vector_at(dictionary[word_length], 0), current_guess);


                if (my_string_compare(word_key, word_family) == 0)
                {
                    printf("WRONG. There are no %c's in this word.\n\n", current_guess);
                    guess_count--;
                }

                my_string_assignment(&word_key, word_family);

                generic_vector_destroy(&largest_family);
                avl_tree_destroy(&hTree);
                my_string_destroy(&word_family);

                word_family = my_string_init_default();
                hTree = avl_tree_init_default();

                if (guess_count == 0)
                {
                    printf("YOU LOSE!!! >:]\n The word I was thinking was: ");
                    my_string_insertion(generic_vector_at(dictionary[word_length], 0), stdout);
                    printf("\n\n");
                    break;
                }

                if (my_string_compare((MY_STRING)generic_vector_at(dictionary[word_length], 0), word_key) == 0)
                {
                    if (generic_vector_get_size(dictionary[word_length]) == 1)
                    {
                        printf("YOU WIN!! >:[\n The word I was thinking was: ");
                        my_string_insertion(generic_vector_at(dictionary[word_length], 0), stdout);
                        printf("\n\n");
                        break;
                    }
                }


            } while (guess_count >= 0);

            avl_tree_destroy(&hTree);
            my_string_destroy(&word_key);
            my_string_destroy(&guess_list);
            my_string_destroy(&word_family);

            for (i = 0; i < SIZE; i++)
            {
                generic_vector_destroy(&dictionary[i]);
            }
            free(dictionary);
        } while (continue_prompt());
    }

}
GENERIC_VECTOR* skim_dictionary(void)
{
    GENERIC_VECTOR* hVector = (GENERIC_VECTOR*)malloc(SIZE * sizeof(GENERIC_VECTOR));

    if (hVector == NULL)
    {
        printf("Failure to allocate space");
    }

    MY_STRING hString = NULL;

    FILE* fp;
    int i;


    fp = fopen("dictionary.txt", "r");

    if (fp == NULL)
    {
        printf("Failed to open file.");
        exit(1);
    }

    for (i = 0; i < SIZE; i++)
    {
        hVector[i] = generic_vector_init_default(my_string_init_copy, my_string_destroy);

        if (hVector[i] == NULL)
        {
            printf("Failed to initialize vector.");
            exit(1);
        }
    }
    hString = my_string_init_default();

    if (hString == NULL)
    {
        printf("Failed to initialize string.");
        exit(1);
    }

    while (my_string_extraction(hString, fp))
    {
        if (my_string_get_size(hString) < 30)
        {
            if (!generic_vector_push_back(hVector[my_string_get_size(hString)], hString))
            {
                printf("failed");
                exit(1);
            }
        }
    }
    my_string_destroy(&hString);
    fclose(fp);


    return hVector;
}
void read_dictionary(GENERIC_VECTOR set_of_words[])
{
    MY_STRING hString = NULL;
    FILE* fp;



    hString = my_string_init_default();

    if (hString == NULL)
    {
        printf("Couldn't init the string handle\n");
        exit(1);
    }

    fp = fopen("dictionary.txt", "r");

    if (fp == NULL)
    {
        printf("Couldn't open dictionary.txt for reading.\n");
        exit(1);
    }

    while (my_string_extraction(hString, fp))
    {

        generic_vector_push_back(set_of_words[my_string_get_size(hString)], hString);

    }


    fclose(fp);
    my_string_destroy(&hString);


}
Boolean running_total_prompt(void)
{
    char c;

    printf("Do you want a running total of words remaining? y/n ");

    scanf("%c", &c);
    clear_keyboard();


    while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
    {
        printf("Invalid answer. Please type y or n\n");
        scanf("%c", &c);
        clear_keyboard();
    }


    return c == 'y' || c == 'Y';
}
void get_total(int word_length, GENERIC_VECTOR set_of_words[])
{

    int i;


    for (i = 0; i < word_length; i++)
    {
        set_of_words[i] = NULL;
    }


    for (i = 0; i < word_length; i++)
    {
        set_of_words[i] = generic_vector_init_default(my_string_init_copy, my_string_destroy);

        if (set_of_words[i] == NULL)
        {
            printf("Unable to create a generic vector\n");
            exit(1);
        }
    }



    read_dictionary(set_of_words);




    int answer = generic_vector_get_size(set_of_words[i]);
    printf("%d", answer);




    for (i = 0; i < word_length; i++)
    {
        generic_vector_destroy(&set_of_words[i]);
    }

}
Boolean continue_prompt(void)
{
    char c;

    printf("Play again? y/n: ");
    scanf("%c", &c);
    clear_keyboard();

    while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
    {
        printf("Invalid answer. Please type y or n\n");
        scanf("%c", &c);
        clear_keyboard();
    }

    return c == 'y' || c == 'Y';
}
Boolean game_prompt(void)
{

    char c;

    printf("Play Hangman? y/n: ");
    scanf("%c", &c);
    clear_keyboard();

    while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
    {
        printf("Invalid answer. Please type y or n\n");
        scanf("%c", &c);
        clear_keyboard();
    }

    return c == 'y' || c == 'Y';
}
int word_length_prompt(void)
{
    int i = 0;


    printf("How many letters in the word? ");
    scanf("%d", &i);
    clear_keyboard();


    while (i < 0 || i > 29)
    {
        printf("There are no words that length in the dictionary. Please put a different length: ");
        scanf("%d", &i);
        clear_keyboard();
    }



    return i;
}
int guesses_prompt(void)
{
    int guess_count = 0;


    while (guess_count < 1)
    {
        printf("How many guesses? ");
        scanf("%d", &guess_count);
        clear_keyboard();
    }

    return guess_count;
}
char guess_letter(void)
{
    char c;

    printf("Make a guess!\n");
    scanf("%c", &c);

    clear_keyboard();

    if (isalpha(c))
    {
        c = tolower(c);
    }
    else
    {
        printf("Invalid character. Type ONE letter at a time!\n");
        return guess_letter();
    }

    return c;
}
void clear_keyboard(void)
{
    char c;

    scanf("%c", &c);

    while (c != '\n')
    {
        scanf("%c", &c);
    }
}
