#include "rubiks.h"

void rotate_lines(int **table, int line, int offset)
{
    if (offset < 0)
    {
        algo_line(table, line);
    }
    else
    {
        algo_line_reverse(table, line);
    }
}

void rotate_columns(int **table, int column, int offset)
{
    if (offset < 0)
    {
        algo_column(table, column);
    }
    else
    {
        algo_column_reverse(table, column);
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

    //Exo 7
    table[0][0] = 0;
    table[0][1] = 2;
    table[0][2] = 0;
    table[0][3] = 0;
    table[1][0] = 0;
    table[1][1] = 3;
    table[1][2] = 1;
    table[1][3] = 3;
    table[2][0] = 2;
    table[2][1] = 2;
    table[2][2] = 1;
    table[2][3] = 3;
    table[3][0] = 1;
    table[3][1] = 1;
    table[3][2] = 3;
    table[3][3] = 2;

    print_tab(table);

    int *ret_value;
    int *ret_space;
    int lines[4];
    int columns[4];

    lines[0] = BLOCKED;
    lines[1] = EMPTY;
    lines[2] = BLOCKED;
    lines[3] = BLOCKED;
    columns[0] = EMPTY;
    columns[1] = EMPTY;
    columns[2] = EMPTY;
    columns[3] = EMPTY;

    ret_value = look_for_value(table, lines, columns, 0);
    //verif_return(look_for_value(table, lines, columns, 0));

    lines[0] = EMPTY;
    lines[1] = BLOCKED;

    ret_space = look_for_space(table, lines, columns, 0);
    //verif_return(look_for_space(table, lines, columns, 0));  

    rotate_lines(table, ret_value[0], ret_space[1] - ret_value[1]);
    rotate_columns(table, ret_space[1], ret_space[0] - ret_value[0]);

    return 0;
}*/
