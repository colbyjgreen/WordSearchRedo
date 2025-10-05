//
// Created by Colby Green on 10/4/25.
//

#ifndef WORDSEARCHREDO_WORDSEARCH_H
#define WORDSEARCHREDO_WORDSEARCH_H
#include "Placement.h"
#include "WordGrid.h"
#include "Words.h"

class WordSearch {
    Words _word;
    WordGrid _grid;
    Placement _place;
public:
    void startgame();
    void play();
    void findword();
};


#endif //WORDSEARCHREDO_WORDSEARCH_H