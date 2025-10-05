//
// Created by Colby Green on 10/4/25.
//

#include "Placement.h"
void Placement::AskPlacement() {
    int rowstart,rowend,colstart,colend;
    std::string newWord;
    std::cout << "Enter word:";
    std::cin >> newWord;
    std::cout << "Enter Start Coordinates (x y)";
    std::cin >> colstart >> rowstart;
    std::cout << "Enter Ending Coordinates (x y)";
    std:: cin >> colend >> rowend;
    _Words.push_back({rowstart,colstart,rowend,colend,newWord});
    _Words[wordcount].length=newWord.length()-1;
    PlacementDirection();
    PlacementCheck();
}
void Placement::EndPlacement() {
    _WordGrid.Randomize();
}

void Placement::PlacementDirection() {
    if (_Words[wordcount].startcol==_Words[wordcount].endcol) {
        _Words[wordcount].vertical = true;
        if (_Words[wordcount].startrow<_Words[wordcount].endrow) {
            _Words[wordcount].forward=true;
        }
    }
    else if (_Words[wordcount].startrow==_Words[wordcount].endrow) {
        _Words[wordcount].horizontal = true;
        if (_Words[wordcount].startcol<_Words[wordcount].endcol) {
            _Words[wordcount].forward=true;
        }
    }
    else {
        _Words[wordcount].diagonal = true;
    }
}

void Placement::PlacementCheck() {
   if (ValidLength()&&ValidPlacement()&&NotOverlap()){
       _WordGrid.WordAdd(_Words[wordcount]);
       _WordGrid.print();
       wordcount++;
   }
   else {
       _Words.pop_back();
   }
}

bool Placement::NotOverlap() {
    int wordcheck=0;
    if (_Words[wordcount].forward) {
        if (_Words[wordcount].horizontal) {
            for (int i = 0; i<=_Words[wordcount].length;i++) {
                if (_WordGrid.getLetter(_Words[wordcount].startrow,_Words[wordcount].startcol+i)!='-'&&_WordGrid.getLetter(_Words[wordcount].startrow,_Words[wordcount].startcol+i)!=_Words[wordcount].word.at(i)) {
                    std::cout << "Error, Word in Way \n";
                    return false;
                }
                if (_WordGrid.getLetter(_Words[wordcount].startrow,_Words[wordcount].startcol+i)==_Words[wordcount].word.at(i)) {
                    wordcheck++;
                }
            }
        }
        if (_Words[wordcount].vertical) {
            for (int i = 0; i<=_Words[wordcount].length;i++) {
                if (_WordGrid.getLetter(_Words[wordcount].startrow+i,_Words[wordcount].startcol)!='-'&&_WordGrid.getLetter(_Words[wordcount].startrow,_Words[wordcount].startcol+i)!=_Words[wordcount].word.at(i)) {
                    std::cout << "Error, Word in Way \n";
                    return false;
                }
                if (_WordGrid.getLetter(_Words[wordcount].startrow+i,_Words[wordcount].startcol)==_Words[wordcount].word.at(i)) {
                    wordcheck++;
                }
            }
        }
    }
    if (!_Words[wordcount].forward) {
        if (_Words[wordcount].horizontal) {
            for (int i = 0; i<=_Words[wordcount].length;i++) {
                if (_WordGrid.getLetter(_Words[wordcount].startrow,_Words[wordcount].startcol-i)!='-'&&_WordGrid.getLetter(_Words[wordcount].startrow,_Words[wordcount].startcol-i)!=_Words[wordcount].word.at(i)) {
                    std::cout << "Error, Word in Way \n";
                    return false;
                }
                if (_WordGrid.getLetter(_Words[wordcount].startrow,_Words[wordcount].startcol-i)==_Words[wordcount].word.at(i)) {
                    wordcheck++;
                }
            }
        }
        if (_Words[wordcount].vertical) {
            for (int i = 0; i<=_Words[wordcount].length;i++) {
                if (_WordGrid.getLetter(_Words[wordcount].startrow-i,_Words[wordcount].startcol)!='-'&&_WordGrid.getLetter(_Words[wordcount].startrow-i,_Words[wordcount].startcol)!=_Words[wordcount].word.at(i)) {
                    std::cout << "Error, Word in Way \n";
                    return false;
                }
                if (_WordGrid.getLetter(_Words[wordcount].startrow-i,_Words[wordcount].startcol)==_Words[wordcount].word.at(i)) {
                    wordcheck++;
                }
            }
        }
    }
    if (_Words[wordcount].diagonal) {
        if (_Words[wordcount].endrow>_Words[wordcount].startrow) {
            if (_Words[wordcount].endcol>_Words[wordcount].startcol) {
                for (int i = 0; i<=_Words[wordcount].length;i++) {
                    if (_WordGrid.getLetter(_Words[wordcount].startrow+i,_Words[wordcount].startcol+i)!='-'&&_WordGrid.getLetter(_Words[wordcount].startrow+i,_Words[wordcount].startcol+i)!=_Words[wordcount].word.at(i)) {
                        std::cout << "Error, Word in Way \n";
                        return false;
                    }
                    if (_WordGrid.getLetter(_Words[wordcount].startrow+i,_Words[wordcount].startcol+i)==_Words[wordcount].word.at(i)) {
                        wordcheck++;
                    }
                }
            }
            if (_Words[wordcount].endcol<_Words[wordcount].startcol) {
                for (int i = 0; i<=_Words[wordcount].length;i++) {
                    if (_WordGrid.getLetter(_Words[wordcount].startrow+i,_Words[wordcount].startcol-i)!='-'&&_WordGrid.getLetter(_Words[wordcount].startrow+i,_Words[wordcount].startcol-i)!=_Words[wordcount].word.at(i)) {
                        std::cout << "Error, Word in Way \n";
                        return false;
                    }
                    if (_WordGrid.getLetter(_Words[wordcount].startrow+i,_Words[wordcount].startcol-i)==_Words[wordcount].word.at(i)) {
                        wordcheck++;
                    }
                }
            }
        }
        if (_Words[wordcount].endrow<_Words[wordcount].startrow) {
            if (_Words[wordcount].endcol>_Words[wordcount].startcol) {
                for (int i = 0; i<=_Words[wordcount].length;i++) {
                    if (_WordGrid.getLetter(_Words[wordcount].startrow-i,_Words[wordcount].startcol+i)!='-'&&_WordGrid.getLetter(_Words[wordcount].startrow-i,_Words[wordcount].startcol+i)!=_Words[wordcount].word.at(i)) {
                        std::cout << "Error, Word in Way \n";
                        return false;
                    }
                    if (_WordGrid.getLetter(_Words[wordcount].startrow-i,_Words[wordcount].startcol+i)==_Words[wordcount].word.at(i)) {
                        wordcheck++;
                    }
                }
            }
            if (_Words[wordcount].endcol<_Words[wordcount].startcol) {
                for (int i = 0; i<=_Words[wordcount].length;i++) {
                    if (_WordGrid.getLetter(_Words[wordcount].startrow-i,_Words[wordcount].startcol-i)!='-'&&_WordGrid.getLetter(_Words[wordcount].startrow-i,_Words[wordcount].startcol-i)!=_Words[wordcount].word.at(i)) {
                        std::cout << "Error, Word in Way \n";
                        return false;
                    }
                    if (_WordGrid.getLetter(_Words[wordcount].startrow-i,_Words[wordcount].startcol-i)==_Words[wordcount].word.at(i)) {
                        wordcheck++;
                    }
                }
            }
        }
    }
    if (wordcheck==_Words[wordcount].length) {
        std::cout << "Duplicate Word";
    }
    return true;
}

bool Placement::ValidPlacement() {
    if (_Words[wordcount].horizontal) {
        if (_Words[wordcount].forward) {
            if (_Words[wordcount].length+_Words[wordcount].startcol<=_WordGrid.getCollumns()) {
                return true;
            }
        }
        else {
            if (_Words[wordcount].startcol-_Words[wordcount].length>=0) {
                return true;
            }
        }
    }
    if (_Words[wordcount].vertical) {
        if (_Words[wordcount].forward) {
            if (_Words[wordcount].length+_Words[wordcount].startrow<=_WordGrid.getRows()) {
                return true;
            }
        }
        else {
            if (_Words[wordcount].startrow-_Words[wordcount].length>=0) {
                return true;
            }
        }
    }
    if (_Words[wordcount].diagonal) {
        if (_Words[wordcount].startrow<_Words[wordcount].endrow) {
            if (_Words[wordcount].startcol<_Words[wordcount].endcol) {
                if (_Words[wordcount].length+_Words[wordcount].startrow<=_WordGrid.getRows()&&_Words[wordcount].length+_Words[wordcount].startcol<=_WordGrid.getRows()) {
                    return true;
                }
            }
            if (_Words[wordcount].startcol>_Words[wordcount].endcol) {
                if (_Words[wordcount].length+_Words[wordcount].startrow<=_WordGrid.getRows()&&_Words[wordcount].startcol-_Words[wordcount].length>=0) {
                    return true;
                }
            }
        }
        if (_Words[wordcount].startrow>_Words[wordcount].endrow) {
            if (_Words[wordcount].startcol<_Words[wordcount].endcol) {
                if (_Words[wordcount].startrow-_Words[wordcount].length>=0&&_Words[wordcount].length+_Words[wordcount].startcol<=_WordGrid.getRows()) {
                    return true;
                }
            }
            if (_Words[wordcount].startcol>_Words[wordcount].endcol) {
                if (_Words[wordcount].startrow-_Words[wordcount].length>=0&&_Words[wordcount].startcol-_Words[wordcount].length>=0) {
                    return true;
                }
            }
        }
    }

    std::cout << "Error in Placement \n";
    return false;
}

bool Placement::ValidLength() {
    if (_Words[wordcount].horizontal) {
        if (_Words[wordcount].length==std::abs((_Words[wordcount].endcol-_Words[wordcount].startcol))) {
            return true;
        }
    }
    if (_Words[wordcount].vertical) {
        if (_Words[wordcount].length==std::abs((_Words[wordcount].endrow-_Words[wordcount].startrow))) {
            return true;
        }
    }
    if (_Words[wordcount].diagonal) {
        if (_Words[wordcount].length==std::abs((_Words[wordcount].endcol-_Words[wordcount].startcol))&&_Words[wordcount].length==std::abs((_Words[wordcount].endrow-_Words[wordcount].startrow))) {
            return true;
        }
    }
    std::cout << "Error in Length \n";
    return false;
}