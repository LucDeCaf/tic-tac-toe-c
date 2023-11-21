#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void print_board(const int board[3][3])
{
    char output[] = "- - -";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            output[j * 2] = board[i][j] + '0';
        }
        printf("%s\n", output);
    }
}

int move_is_valid(const int board[3][3], int x, int y)
{
    return !(board[x][y] || x < 0 || y < 0 || x > 2 || y > 2);
}

int get_winner(const int board[3][3])
{
    /*
        0: No winner
        1: Player 1 wins
        2: Player 2 wins
        3: Draw
    */
    int winner = 0;
    int spaces_checked = 0;
    int can_be_draw = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            /*
                Win logic goes here

                If a winner is found, the loop will break early and spaces_checked
                will never reach its max value of 9; therefore the only possibilities
                there are either a draw or no winner yet.
            */

            spaces_checked++;
            if (!board[i][j]) {
                can_be_draw = 0;
            }
        }
    }

    return winner ? winner : (can_be_draw ? 3 : 0);
}

int play_game()
{
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int current_turn = 1;
    int winner;
    int gamemode;
    int x, y;

    printf("--- TIC TAC TOE ---\n");
    printf("Note: Enter moves in the format: 'x;y', eg. '2;3'\n\n");
    printf("Type 1: Play game (human vs. human)\n");
    printf("Type 2: Exit\n");

    scanf(" %d", &x);

    if (x == 2)
    {
        return 0;
    }

    gamemode = x;

    system("clear");

    while (1)
    {
        printf("--- TIC TAC TOE ---\n");
        print_board(board);

        printf("Enter your move in the format 'x;y' or enter 0 to exit\n");
        scanf(" %d;%d", &x, &y);

        if (x == 0)
        {
            return 0;
        }

        x--;
        y--;

        if (!move_is_valid(board, x, y))
        {
            system("clear");
            printf("-- Invalid move --\n");
            continue;
        }

        board[x][y] = current_turn;

        winner = get_winner(board);

        if (winner)
        {
            return winner;
        }

        current_turn = current_turn == 1 ? 2 : 1;

        system("clear");
    }
}
