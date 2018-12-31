#include "rubiks.h"

int *look_for_space(int **table, int *lines, int *columns, int value)
{
    int i, j, *ret;

    for (i = 0 ; i < 4 ; i++)
    {
        for (j = 0 ; j < 4 ; j++)
        {
            if ((!(lines[i])) && (!(columns[j])) && (table[i][j] != value))
            {
                ret=malloc(2*sizeof(int));
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return NULL;
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

    //Exo 5
    table[0][0] = 2;
    table[0][1] = 1;
    table[0][2] = 3;
    table[0][3] = 0;
    table[1][0] = 0;
    table[1][1] = 0;
    table[1][2] = 1;
    table[1][3] = 1;
    table[2][0] = 2;
    table[2][1] = 2;
    table[2][2] = 3;
    table[2][3] = 0;
    table[3][0] = 2;
    table[3][1] = 3;
    table[3][2] = 1;
    table[3][3] = 3;

    print_tab(table);

    int lines[4];
    int columns[4];

    lines[0] = BLOCKED ;
    lines[1] = BLOCKED ;
    lines[2] = EMPTY ;
    lines[3] = BLOCKED ;
    columns[0] = EMPTY ;
    columns[1] = EMPTY ;
    columns[2] = BLOCKED ;
    columns[3] = BLOCKED ;
    verif_return(look_for_space(table, lines, columns, 1));
    verif_return(look_for_space(table, lines, columns, 2));

    return 0;
}*/
