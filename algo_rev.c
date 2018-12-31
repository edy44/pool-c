#include "rubiks.h"

void algo_line_reverse(int **table, int line)
{
    int buffer;
    int i;

    buffer = table[line][3];
    for (i = 3 ; i > 0 ; i--)
    {
        table[line][i] = table[line][i-1];
    }
    table[line][0] = buffer;

    if (PRINT_SQUARE_DEBUG__ == 1)
    {
        printf("\n\nTranslation de la Ligne %d vers la Droite\n\n", line);
        print_tab(table);
        sleep(SLEEP);
    }
}

void algo_column_reverse(int **table, int column)
{
    int buffer;
    int i;

    buffer = table[3][column];
    for (i = 3 ; i > 0 ; i--)
    {
        table[i][column] = table[i-1][column];
    }
    table[0][column] = buffer;
    
    if (PRINT_SQUARE_DEBUG__ == 1)
    {
        printf("\n\nTranslation de la Colonne %d vers le Bas\n\n", column);
        print_tab(table);
        sleep(SLEEP);
    }
}

void algo_square_reverse(int **table, int square)
{
    int line, column, buffer;

    if (square == 0)
    {
        line = 0;
        column = 0;
    }
    else if (square == 1)
    {
        line = 0;
        column = 2;
    }
    else if (square == 2)
    {
        line = 2;
        column = 0;
    }
    else 
    {
        line = 2;
        column = 2;
    }

    buffer = table[line][column];
    table[line][column] = table[line][column+1];
    table[line][column+1] = table[line+1][column+1];
    table[line+1][column+1] = table[line+1][column];
    table[line+1][column] = buffer;

    if (PRINT_SQUARE_DEBUG__ == 1)
    {
        printf("\n\nRotation du Carré %d dans le sens Anti-Horaire\n\n", square);
        print_tab(table);
        sleep(SLEEP);
    }
}

/*int main(int argc, char const *argv[])
{
    int **table;
    int i, j, size;

    //Initialisation du tableau
    size = 4;
    table = malloc(size*sizeof(int));

    for (i = 0 ; i < size ; i++)
    {
        table[i] = malloc(size*sizeof(int));;
    }

    for (i = 0 ; i < size ; i++)
    {
        for (j = 0 ; j < size ; j++)
        {
            if (i < 2) 
            {
                if ( j < 2)
                {
                    table[i][j] = 0;
                }
                else
                {
                    table[i][j] = 1;
                }
            }
            else
            {
                if ( j < 2)
                {
                    table[i][j] = 2;
                }
                else
                {
                    table[i][j] = 3;
                }
            }
        }
    }

    //Exo 1
    print_tab(table);

    //Exo 2
    algo_line(table, 0);
    algo_column(table, 0);
    algo_square(table, 0);

    //Exo 3
    algo_square_reverse(table, 0);
    algo_column_reverse(table, 0);
    algo_line_reverse(table, 0);

    return 0;
}*/
