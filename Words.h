//
// Created by Colby Green on 10/4/25.
//

#ifndef WORDSEARCHREDO_WORDS_H
#define WORDSEARCHREDO_WORDS_H
#include <iostream>

struct Words {
    int startrow,startcol,endrow,endcol;
    std::string word;
    int length;
    bool horizontal,vertical,diagonal,forward;

};


#endif //WORDSEARCHREDO_WORDS_H