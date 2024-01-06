#include "../header/tic_tac_toe.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3] = {0};
const char PLAYER = 'X';
const char COMPUTER = 'O';

short main_tic_tac_toe ()
{
    char winner = ' ';
    char response = ' ';

    do
    {
        winner = ' ';
        response = ' ';
        reset_board ();
        while (winner == ' ' && check_free_spaces () != 0)
        {
            print_board ();
            player_move ();
            winner = check_winner ();
            if (winner != ' ' || check_free_spaces () == 0)
            {
                break;
            }
            computer_move ();
            winner = check_winner ();
            if (winner != ' ' || check_free_spaces () == 0)
            {
                break;
            }
        }
        print_board ();
        print_winner (winner);
        printf ("would you like to play again? (y/n): ");
        while ((getchar ()) != '\n')
            ;
        scanf ("%c", &response);
        response = tolower (response);
    } while (response == 'y');

    return 0;
}

void reset_board ()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void print_board ()
{
    printf (" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf ("---|---|---\n");
    printf (" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf ("---|---|---\n");
    printf (" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf ("---|---|---\n");
    printf ("\n");
}

int check_free_spaces ()
{
    int free_spaces = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                free_spaces--;
            }
        }
    }
    return free_spaces;
}

void player_move ()
{
    int row = 0;
    int column = 0;

    do
    {
        printf ("Enter row number [1-3] and column number [1-3] (<row> <column> "
                "<enter>): ");
        scanf ("%d %d", &row, &column);
        row--;
        column--;
        if (board[row][column] != ' ')
        {
            printf ("invalid move!\n");
        }
        else
        {
            board[row][column] = PLAYER;
            break;
        }
    } while (board[row][column] != ' ');
}

void computer_move ()
{
    // creates a seed based on current time
    srand (time (0));
    int row = 0;
    int column = 0;

    if (check_free_spaces () > 0)
    {
        do
        {
            row = rand () % 3;
            column = rand () % 3;
        } while (board[row][column] != ' ');
        board[row][column] = COMPUTER;
    }
    else
    {
        print_winner (' ');
    }
}

char check_winner ()
{
    // row check
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    // column check
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // diagonal check
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[0][0] == board[2][0])
    {
        return board[0][2];
    }
    return ' ';
}

void print_winner (char winner)
{
    if (winner == PLAYER)
    {
        printf ("you win\n");
    }
    else if (winner == COMPUTER)
    {
        printf ("you lose\n");
    }
    else
    {
        printf ("It is a draw\n");
    }
}
