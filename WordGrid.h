//
// Created by Colby Green on 10/4/25.
//

#ifndef WORDSEARCHREDO_WORDGRID_H
#define WORDSEARCHREDO_WORDGRID_H
#include <iostream>
#include "Words.h"
class WordGrid {
    std::vector<std::vector<char>> _WordGrid;
    int _Collumns;
    int _Rows;
public:
    const char getLetter(int row, int col) const;
    void setLetter(int row, int col, char letter);
    void WordAdd(const Words &Word);
    WordGrid();
    WordGrid(int row);
    WordGrid(int row, int col);
    void Randomize();
    void print() const;
    void setRows(int length);
    void setCollumns(int length);
    const int getRows() const;
    const int getCollumns() const;
};


#endif //WORDSEARCHREDO_WORDGRID_H