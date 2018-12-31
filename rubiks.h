#ifndef RUBIKS_H_
#define RUBIKS_H_

#define PRINT_SQUARE_DEBUG__ 1
#define EMPTY 0
#define BLOCKED 1
#define SLEEP 1

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void print_tab(int **table);
void color_number(int n);
void algo_line(int **table, int line);
void algo_column(int **table, int column);
void algo_square(int **table, int square);
void algo_line_reverse(int **table, int line);
void algo_column_reverse(int **table, int column);
void algo_square_reverse(int **table, int square);
int is_in_line(int **table, int line, int value);
int is_in_col(int **table, int column, int value);
int *look_for_space(int **table, int *lines, int *columns, int value);
int *look_for_value(int **table, int *lines, int *columns, int value);
void rotate_lines(int **table, int line, int offset);
void rotate_columns(int **table, int column, int offset);
void build_first_line(int **table);
void line_to_square(int **table, int line);
void build_last_line(int **table);
void push_it_up(int **table);
void build_final_line(int **table);

#endif
