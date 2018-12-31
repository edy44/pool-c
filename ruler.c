#include "rubiks.h"

/*void print_tab(int **table)
{
    int count;
    count = 0;
    while (count < 4)
    {
        printf("----------------- \n");
        printf("| %d | %d | %d | %d | \n" ,
        table[count][0], table[count][1],
        table[count][2], table[count][3]);
        count++;
    }
    printf("----------------- \n\n");
}*/


void color_number(int n)
{
    if (n == 1)
    {
        printf("\033[0;34m");
        printf("%d ", n);
        printf("\033[0;37m");
    }
    else if (n == 2)
    {
        printf("\033[0;32m");
        printf("%d ", n);
        printf("\033[0;37m");
    }
    else if (n == 3)
    {
        printf("\033[0;33m");
        printf("%d ", n);
        printf("\033[0;37m");
    }
    else
    {
        printf("%d ", n);
    }
}

void print_tab(int **table)
{
    int i, j;
    for (i = 0 ; i < 4 ; i++)
    {
        printf("----------------- \n");
        for (j = 0 ; j < 4 ; j++)
        {
            printf("| ");
            color_number(table[i][j]);
        }
        printf("| \n");
    }
    printf("----------------- \n\n");
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

    return 0;
}*/
