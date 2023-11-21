#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int player_1_wins = 0;
    int player_2_wins = 0;
    int draws = 0;

    system("clear");

    int winner = play_game();
    char play_again;

    while (1)
    {
        system("clear");

        switch (winner)
        {
        case 0:
            printf("-- Summary --\n");
            printf("Player 1 wins: %d\n", player_1_wins);
            printf("Player 2 wins: %d\n", player_2_wins);
            printf("Draws: %d\n", draws);
            return 0;
            break;

        case 1:
            printf("Player 1 wins!\n\n");
            player_1_wins++;
            break;

        case 2:
            printf("Player 2 wins!\n\n");
            player_2_wins++;
            break;

        case 3:
            printf("Draw.\n\n");
            draws++;
            break;

        default:
            printf("Something went wrong :('n");
            return 1;
            break;
        }

        winner = play_game();
    }

    // Loop should theoretically never break; therefore exiting the loop while running the program is an error.
    return 1;
}
