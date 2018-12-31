#include "rubiks.h"

void build_last_line(int **table)
{
    int value, line, line_init, column_init;
    int *ret_value;
    int *ret_space;
    int lines[4];
    int columns[4];
    
    //On initialise la variable valeur avec la premiere valeur du cube
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

    //On initialise la ligne de recherche à 1 (la ligne 0 constitura les résultats)
    line = 2;
    //On boucle sur les 3 dernieres lignes
    while (line >= 0)
    {
        //On cherche si la valeur est présente dans la ligne
        if (!(is_in_line(table, line, value)))
        {
            //On libère la ligne pour la recherche et on cherche la valeur
            lines[line] = EMPTY;
            ret_value = look_for_value(table, lines, columns, value);
            lines[line] = BLOCKED;


            //On libère la ligne à construire pour chercher un espace vide
            //On sait que cet espace existe, var on a trouvé une valeur compatible ailleurs
            lines[line_init] = EMPTY;
            ret_space = look_for_space(table, lines, columns, value);
            lines[line_init] = BLOCKED;

            //On comble la différence de colonnes entre la valeur cherchée et l espace vide avec des rotations de lignes
            while (ret_space[1] != ret_value[1])
            {
                if ((ret_space[1] >= 2) && (ret_value[0] == 0))
                {
                    algo_column_reverse(table, 0);
                    algo_column_reverse(table, 1); 
                    algo_column_reverse(table, 0);
                    algo_column_reverse(table, 1);  
                }
                if ((ret_space[1] >= 2) && (ret_value[0] == 1))
                {
                    algo_column(table, 0);
                    algo_column(table, 1); 
                    algo_column(table, 0);
                    algo_column(table, 1);   
                }
                rotate_lines(table, ret_value[0], ret_space[1] - ret_value[1]);
                if ((ret_space[1] >= 2) && (ret_value[0] == 0))
                {
                    algo_column(table, 0);
                    algo_column(table, 1); 
                    algo_column(table, 0);
                    algo_column(table, 1);   
                }
                if ((ret_space[1] >= 2) && (ret_value[0] == 1))
                {
                    algo_column_reverse(table, 0);
                    algo_column_reverse(table, 1);
                    algo_column_reverse(table, 0);
                    algo_column_reverse(table, 1); 
                }
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
            //On comble la différence de lignes entre la valeur cherchée et l espace vide avec des rotations de colonnes
            while (ret_space[0] != ret_value[0])
            {
                if ((ret_space[1] < 2))
                {
                    algo_line_reverse(table, 0);
                    algo_line_reverse(table, 0);
                    algo_line_reverse(table, 1);
                    algo_line_reverse(table, 1);   
                }
                rotate_columns(table, ret_value[1], ret_space[0] - ret_value[0]);
                if ((ret_space[1] < 2))
                {
                    algo_line(table, 0);
                    algo_line(table, 0);
                    algo_line(table, 1);
                    algo_line(table, 1);   
                }
                //Si la colonne de la valeur est plus petite, on décrémente de 1 la valeur de la colonne, l'inverse sinon
                if (ret_value[0] < ret_space[0])
                {
                    ret_value[0]++;
                }
                else
                {
                    ret_value[0]--;
                }
            }
        }
        else
        {
            //Si on n'a plus de valeurs dans la ligne on passe à la ligne suivante
            line--;
        }
    }
}

void push_it_up(int **table)
{
    algo_column(table, 2);
    algo_column(table, 2);
    algo_column(table, 3);
    algo_column(table, 3);
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

    //Premier
    print_tab(table);
    build_first_line(table);
    line_to_square(table, 0);

    //Second
    build_last_line(table);
    line_to_square(table, 3);
    push_it_up(table);

    return 0;
}*/
