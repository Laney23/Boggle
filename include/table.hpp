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
#include <vector>
#include <numeric>
#include <list>
#include <algorithm>
#include "../include/base.hpp"


struct Coordinates {
    int row;
    int column;
};

class Table {
    int dim;
    char *matrix;
    std::vector<std::string> word_list;
    std::vector<Coordinates> findNeighbors(int row, int column);
    void stringBuilder(std::vector<char> word, Coordinates coords);
    bool borderCheck(int row, int column) { return (row >= 0 && row < dim && column >= 0 && column < dim); }
    static bool sorter(const std::string& a, const std::string& b);
    
public:
    Table(int dimension) { dim = dimension; matrix = new char[dimension*dimension]; word_list.reserve(100); }
    int addTable();
    int findAllWords();
    void setVal(int row, int column, char value) { matrix[row + column*dim] = value; }
    char getVal(int row, int column) { return matrix[row + column*dim]; }
    void print();
};

#endif /* table_hpp */
