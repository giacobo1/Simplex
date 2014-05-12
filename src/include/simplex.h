// TODO: fazer um parser decente

#ifndef SIMPLEX_H
#define SIMPLEX_H
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

std::vector< std::vector<float> > readInput(const char *argv);

int* calc_simplex(float** matrix,int lines, int columns);
bool find_entry_var(float** matrix,int lines,int columns, int* leaving);
int find_leaving_var(float** matrix,int lines,int  columns,int* leaving);
void erase_pivot_column(float** matrix,int lines,int columns,int piv ,int* leaving);
#endif