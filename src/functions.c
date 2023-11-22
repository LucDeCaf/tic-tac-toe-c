#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

const int WIN_STATES[8][3][2] = {
    {{0, 0}, {1, 0}, {2, 0}},
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 2}, {1, 2}, {2, 2}},

    {{0, 0}, {0, 1}, {0, 2}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{2, 0}, {2, 1}, {2, 2}},

    {{0, 0}, {1, 1}, {2, 2}},
    {{2, 0}, {1, 1}, {0, 2}},
};

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
    int can_be_draw = 1;
    int can_win;
    int prev_tile;
    int row, col;
    int i, j;

    for (i = 0; i < 8; i++) {
        can_win = 1;
        prev_tile = 0;

        for (j = 0; j < 3; j++) {
            row = WIN_STATES[i][j][0];
            col = WIN_STATES[i][j][1];

            if (!prev_tile) {
                prev_tile = board[row][col];
            }

            // // Debugging info because built-in debuggers are hard

            // printf("\n\t-- START DEBUGGING --\n\n");
            // printf("i: %d\n", i);
            // printf("j: %d\n", j);
            // printf("can_win: %d\n", can_win);
            // printf("row: %d\n", row);
            // printf("col: %d\n", col);
            // printf("prev_tile: %d\n", prev_tile);
            // printf("board[row][col]: %d\n", board[row][col]);
            // printf("\n\t-- END DEBUGGING --\n\n");

            // If the current tile is empty, skip this win state and disallow draws
            if (!board[row][col]) {
                can_be_draw = 0;
                can_win = 0;
                break;
            }

            // If the current tile's value does not match the previous tile's value, skip this win state            
            if (board[row][col] != prev_tile) {
                can_win = 0;
                break;
            }
        }

        if (can_win) {
            winner = prev_tile;
            break;
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

        printf("Enter the row or enter 0 to exit\n");
        scanf(" %d", &x);

        printf("Enter the column or enter 0 to exit\n");
        scanf(" %d", &y);

        if (x == 0 || y == 0)
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
