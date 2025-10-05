//
// Created by Colby Green on 10/4/25.
//

#ifndef WORDSEARCHREDO_PLACEMENT_H
#define WORDSEARCHREDO_PLACEMENT_H
#include <iostream>
#include "WordGrid.h"
#include "Words.h"
class Placement {
    WordGrid _WordGrid;
    std::vector<Words> _Words;
    int wordcount=0;
    void PlacementCheck();
    bool ValidLength();
    bool ValidPlacement();
    bool NotOverlap();
    void PlacementDirection();
public:
    void AskPlacement();
    void EndPlacement();
};


#endif //WORDSEARCHREDO_PLACEMENT_H