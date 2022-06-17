/*This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#include <stdio.h>
#include <stdlib.h>

#define DIM 3
#define RND 9
#define SIZE 10

void PutChoice(int, char [][3], int);
void Display(char [DIM][DIM]);
void Status(char [DIM][DIM], int, char *);
int IsValid(char [DIM][DIM], int);


int main(void)
{
    char board[DIM][DIM];
    int player = 1;
    int choice;
    int round = 0;
    int empty_buffer;
    char *p_stream = (char *) malloc(SIZE * sizeof(char)), *p_endptr;
    
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            board[i][j] = 3 * i + j + 1 + '0';

    system("clear");        //If you are using Windows, change "clear" to "cls".
    Display(board);

    printf("\n\nPlayer 1 has (X), player 2 has (O).\n\n");
    do {       
        ++round;
        if (player % 2 == 0)
            player = 2;
        else
            player = 1;
        
        do{
            printf("\n\nPlayer %d is playing. Enter your choice: ", player);
            fgets(p_stream, SIZE, stdin);
            for (int i = 0; i < SIZE; i++)
            {
                if (p_stream[i] == '\n')
                    empty_buffer = 1;
            }
            if (!empty_buffer)
                while (getchar() != '\n');
            choice = strtol(p_stream, &p_endptr, 10);
        } while ((choice < 1) || (choice > 9) || (!IsValid(board, choice)));

        PutChoice(player, board, choice);
        system("clear");    //If you are using Windows, change "clear" to "cls".
        Display(board);
        Status(board, player, p_stream);
        ++player;
    } while (round < RND);

    printf("\n\nGame is a tie.\n\n");
    free(p_stream);
    return 0;
}

void Display(char array[DIM][DIM])
{
    for (int i = 0; i < DIM; i++)
    {
        if (i != 0)
            printf("\n-----\n");
        for (int j = 0; j < DIM; j++)
        {
            printf("%c", array[i][j]);
            if (j != 2)
                printf("|");
        }
    }
}

void PutChoice(int p, char array[][DIM], int choice)
{
    int i = (choice - 1) / DIM;
    int j = (choice - 1) % DIM;
    switch (p)
    {
    case 1:
        array[i][j] = 'X';
        break;
    
    case 2:
        array[i][j] = 'O';
        break;
    }
}

void Status(char array[DIM][DIM], int p, char *p_str)
{
    int i;
    for (i = 0; i < DIM; i++)
    {
        if ((array[i][0] == array[i][1]) && (array[i][1] == array[i][2]))
        {
            printf("\n\nPlayer %d has won the game.\n", p);
            free(p_str);
            p_str = NULL;
            exit(0);
        }    
        if ((array[0][i] == array[1][i]) && (array[1][i] == array[2][i]))
        {
            printf("\n\nPlayer %d has won the game.\n", p);
            free(p_str);
            p_str = NULL;
            exit(0);
        }
    }

    if ((array[0][0] == array[1][1]) && (array[1][1] == array[2][2]))
    {
            printf("\n\nPlayer %d has won the game.\n", p);
            free(p_str);
            p_str = NULL;
            exit(0);
    }

    if ((array[0][2] == array[1][1]) && (array[1][1] == array[2][0]))
    {
            printf("\n\nPlayer %d has won the game.\n"), p;
            free(p_str);
            p_str = NULL;
            exit(0);
    }
}

int IsValid(char array[DIM][DIM], int c)
{
    int i = (c - 1) / DIM;
    int j = (c - 1) % DIM;

    if ((array[i][j] == 'X') || (array[i][j] == 'O'))
        return 0;

    return 1;
}
