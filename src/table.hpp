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


class Table {
    int dim;
    char *matrix;
    
public:
    Table(int dimension) { dim = dimension; matrix = new char[dimension*dimension]; }
    ~Table() { delete[] matrix; }
    int addTable();
    void setVal(int row, int column, char value);
    char getVal(int row, int column);
};

#endif /* table_hpp */
