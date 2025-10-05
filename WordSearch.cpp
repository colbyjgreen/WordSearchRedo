//
// Created by Colby Green on 10/4/25.
//

#include "WordSearch.h"
void WordSearch::startgame() {
    char y='n';
    do {
        _place.AskPlacement();
        std::cout <<"Again? y/n";
        std::cin >> y;
    }while (tolower(y)=='y');
    _place.EndPlacement();
}
