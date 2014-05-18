// NOTA 0: Acho que quando é minimização muda... ver...

// TODO 0: Fazer um output decente (numero de iterações, onde as vars estão, etc..)
// TODO 1: Fazer um parser decente
// TODO 2: Documentar o codigo
// TODO 3: Testar mais e otimizar o codigo.

#ifndef SIMPLEX_H
#define SIMPLEX_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>


void erase_pivot_column(float** matrix,int lines,int columns,int piv ,int* leaving);
bool find_entry_var(float** matrix,int lines,int columns, int* leaving);
void calc_simplex(float** matrix,int lines, int columns);
int find_leaving_var(float** matrix,int lines,int  columns,int* leaving);
float ** parse_input_build_matrix(const char *argv, int *l, int *c);
#endif