//
// Created by Colby Green on 10/4/25.
//

#include "WordGrid.h"
#include "WordSearch.h"

WordGrid::WordGrid() :WordGrid(10){

}

WordGrid::WordGrid(int row): WordGrid(row,row) {

}

WordGrid::WordGrid(int row, int col) : _WordGrid(row,std::vector<char>(col,'-')){
    setCollumns(col);
    setRows(row);
    print();
}


void WordGrid::WordAdd(const Words &Word) {

    if (Word.forward) {
        if (Word.horizontal) {
            for (int i=0; i<=Word.length;i++) {
                setLetter(Word.startrow,Word.startcol+i,Word.word.at(i));
            }
        }
        if (Word.vertical) {
            for (int i=0; i<=Word.length;i++) {
                setLetter(Word.startrow+i,Word.startcol,Word.word.at(i));
            }
        }
    }
    if (!Word.forward) {
        if (Word.horizontal) {
            for (int i=0; i<=Word.length;i++) {
                setLetter(Word.startrow,Word.startcol-i,Word.word.at(i));
            }
        }
        if (Word.vertical) {
            for (int i=0; i<=Word.length;i++) {
                setLetter(Word.startrow-i,Word.startcol,Word.word.at(i));
            }
        }
    }
    if (Word.diagonal) {
        if (Word.startrow<Word.endrow) {
            if (Word.startcol<Word.endcol) {
                for (int i=0; i<=Word.length;i++) {
                    setLetter(Word.startrow+i,Word.startcol+i,Word.word.at(i));
                }
            }
            if (Word.startcol>Word.endcol) {
                for (int i=0; i<=Word.length;i++) {
                    setLetter(Word.startrow+i,Word.startcol-i,Word.word.at(i));
                }
            }
        }
        if (Word.startrow>Word.endrow) {
            if (Word.startcol<Word.endcol) {
                for (int i=0; i<=Word.length;i++) {
                    setLetter(Word.startrow-i,Word.startcol+i,Word.word.at(i));
                }
            }
            if (Word.startcol>Word.endcol) {
                for (int i=0; i<=Word.length;i++) {
                    setLetter(Word.startrow-i,Word.startcol-i,Word.word.at(i));
                }
            }
        }
    }
}


void WordGrid::setCollumns(int length) {
    _Collumns=length;
}
void WordGrid::setRows(int length) {
    _Rows=length;
}
const int WordGrid::getRows() const {
    return _Rows;
}

const int WordGrid::getCollumns() const {
    return _Rows;
}
const char WordGrid::getLetter(int row, int col) const {
    return _WordGrid.at(row).at(col);
}
void WordGrid::setLetter(int row, int col, char letter) {
    _WordGrid.at(row).at(col)=letter;
}

void WordGrid::print() const{
    for (const std::vector<char> &v : _WordGrid) {
        for (const char &c : v) {
            std::cout<<c<<" ";
        }
        std::cout << std::endl;
    }
}

void WordGrid::Randomize() {
    int row=0,col=0;
    srand(time(NULL)); //seed our randomness (every time we call this constructor it will be reseeded)
    for (std::vector<char> &c: _WordGrid) {
        for (char &v : c) {
            if (_WordGrid.at(row).at(col++)=='-')
                v=rand()%('z'-'a')+'a'; //applies our randomness within asciis Z-A
        }
        row++;
        col=0;
    }
    print();
}
