#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void game();

int main()
{
    srand(time(NULL));

    char replay;

    do 
    {   

        game();

        printf("\nWould you like to play again? (y for Yes / n for No): ");
        scanf(" %c", &replay);
    } 
    while (replay == 'y' || replay == 'Y');

    printf("Thanks for Playing.\n");
    return 0;
}

void game()
{
    
    int guessed_num;
    
    int random_num = (rand() % 100) + 1;
    int n = 0;
    while(1)
    {
        while(1)
        {
            char check;
            printf("Guess the integer(1 - 100): ");
            if (scanf("%d%c", &guessed_num, &check) == 2 && check == '\n')
            {
                if(guessed_num < 1 || guessed_num > 100)
                {
                    printf("Try Again!\n");
                    continue;
                }
                else
                {
                break;
                }
            }
            else
            {
                printf("Try Again!\n");

                char c;
                while ((c = getchar()) != '\n' && c != EOF);//to elimainate non-int outputs 
                continue;
            }
        }
        n++ ;

        if (guessed_num == random_num)
        {
            break;
        }

        if (guessed_num<random_num)
        {
            printf("Higher number please!\n");
        }
        else
        {
            printf("Lower number please!\n");
        }
    }
    printf("\nYou guessed correctly in %d tries\n",n);
}