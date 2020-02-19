#ifndef MUDUO_EXAMPLES_SUDOKU_SUDOKU_H
#define MUDUO_EXAMPLES_SUDOKU_SUDOKU_H


#include <string>

using namespace std;

string solveSudoku(const string &puzzle);
const int kCells = 81;
extern const char kNoSolution[];

#endif
