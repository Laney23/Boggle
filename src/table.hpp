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


struct Element {
    char c;
    bool seen;
};

struct Coordinates {
    int row;
    int column;
};

class Table {
    int dim;
    Element *matrix;
    char findNeighbor(int row, int column);
    void resetTable();
    
public:
    Table(int dimension) { dim = dimension; matrix = new Element[dimension*dimension]; }
    ~Table() { delete[] matrix; }
    int addTable();
    void setVal(int row, int column, char value);
    char getVal(int row, int column);
};

#endif /* table_hpp */
