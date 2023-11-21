#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void print_board(const int board[3][3]);
int move_is_valid(const int board[3][3], int x, int y);
int get_winner(const int board[3][3]);
int play_game();

#endif