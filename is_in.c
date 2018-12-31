#include "rubiks.h"

int is_in_line(int **table, int line, int value)
{
    int i;

    for (i = 0 ; i < 4 ; i++)
    {
        if (table[line][i] == value) {
            return 0;
        }
    }
    return 1;
}

int is_in_col(int **table, int column, int value)
{
    int i;

    for (i = 0 ; i < 4 ; i++)
    {
        if (table[i][column] == value) {
            return 0;
        }
    }
    return 1;
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

    //Exo 4
    printf("%d − %d\n", is_in_line(table, 0, 1), is_in_col(table, 2, 3));
    printf("%d − %d\n", is_in_line(table, 3, 1), is_in_col(table, 2, 0));

    return 0;
}*/
