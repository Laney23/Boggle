//
//  table.hpp
//  boggle
//
//  Created by Josh Laney on 8/26/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef table_hpp
#define table_hpp


#include <iostream>
#include "base.hpp"


struct Coordinates {
    int row;
    int column;
};

class Table {
    int dim;
    std::vector<std::string> *word_list;
    Coordinates findNeighbor(int row, int column);
    void resetTable();
    int stringBuilder(std::string *str, Coordinates coords);
    char *matrix;
    bool isValidChar(char c);
    bool borderCheck(int row, int column);
    
public:
    Table(int dimension) { dim = dimension; matrix = new char[dimension*dimension]; word_list.reserve(100); }
    ~Table() { delete[] matrix; }
    int addTable();
    void setVal(int row, int column, char value);
    char getVal(int row, int column);
};

#endif /* table_hpp */
