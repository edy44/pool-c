#include "rubiks.h"

void build_final_line(int **table)
{
    int value, line, column, line_init, column_init;
    int *ret_value;
    int *ret_space;
    int lines[4];
    int columns[4];

    //On initialise la variable valeur avec la premiere valeur de la derniere ligne du cube
    line_init = 3;
    column_init = 0;
    value = table[line_init][column_init];
    
    //Par défaut pour la recherche dans une ligne, on bloque toutes les lignes et on autorise toutes les colonnes
    columns[0] = EMPTY;
    columns[1] = EMPTY;
    columns[2] = EMPTY;
    columns[3] = EMPTY;
    lines[0] = BLOCKED;
    lines[1] = BLOCKED;
    lines[2] = BLOCKED;
    lines[3] = BLOCKED;

    //On initialise la ligne de recherche à 2 (la ligne 4 constitura les résultats)
    line = 2;
    column = 1;

    while (column < 3)
    {
        column++;
        //On cherche si la valeur est présente dans la ligne 2
        if (!(is_in_line(table, line, value)))
        {
            //On cherche la colonne de l'espace vide dans la ligne 3
            lines[3] = EMPTY;
            ret_space = look_for_space(table, lines, columns, value);
            lines[3] = BLOCKED;

            lines[2] = EMPTY;
            ret_value = look_for_value(table, lines, columns, value);
            lines[2] = BLOCKED;
            while (ret_space[1] != ret_value[1])
            {
                rotate_lines(table, ret_value[0], ret_space[1] - ret_value[1]);
                //Si la colonne de la valeur est plus petite, on décrémente de 1 la valeur de la colonne, l'inverse sinon
                if (ret_value[1] < ret_space[1])
                {
                    ret_value[1]++;
                }
                else
                {
                    ret_value[1]--;
                }
            }
            if (ret_space[1] != 3)
            {
                algo_column_reverse(table, ret_space[1]);
                algo_line(table, 3);
                algo_column(table, ret_space[1]);
                algo_line_reverse(table, 3);
            }
            else
            {
                //On se place dans la config suivante :
                // 2   2   2   3    -->  2   2   2   2 
                // 3   3   3   2    -->  3   3   3   3
                algo_line(table, 2);
                algo_square_reverse(table, 3);
            }
        }
    }
    //Si on a 2 dernieres lignes parfaites
    line_to_square(table, 3);
}


int main(int argc, char const *argv[])
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

    table[0][0] = 0;
    table[0][1] = 2;
    table[0][2] = 0;
    table[0][3] = 0;
    table[1][0] = 3;
    table[1][1] = 0;
    table[1][2] = 3;
    table[1][3] = 1;
    table[2][0] = 2;
    table[2][1] = 2;
    table[2][2] = 1;
    table[2][3] = 3;
    table[3][0] = 1;
    table[3][1] = 1;
    table[3][2] = 3;
    table[3][3] = 2;

    //Initialisation
    printf("\n\nRubik's Cube à résoudre\n");
    print_tab(table);
    sleep(SLEEP);

    //Premier
    build_first_line(table);
    line_to_square(table, 0);

    //Second
    build_last_line(table);
    line_to_square(table, 3);
    push_it_up(table);

    //Final
    build_final_line(table);

    printf("\nRubik's Cube Terminé !! :)\n\n");
    print_tab(table);

    return 0;
}
