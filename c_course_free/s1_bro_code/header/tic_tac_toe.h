#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

void reset_board();
void print_board();
int check_free_spaces();
void player_move();
void computer_move();
char check_winner();
void print_winner(char winner);
short main_tic_tac_toe();

#endif // TIC_TAC_TOE_H
