//
//  table.cpp
//  boggle
//
//  Created by Josh Laney on 8/26/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "table.hpp"

using namespace std;

static bool isValidChar(char c);


int Table::addTable()
{
    /* Verify user input */
    string line;
    int row = 0;
    while (row < dim)
    {
        cin >> line;
        for (int column = 0; column < dim; column++)
        {
            if (isValidChar(tolower(line[column])))
                setVal(row, column, tolower(line[column]));
            else
            {
                cout << "Invalid character input.\n";
                return ERROR;
            }
        }
        cin.ignore();
        
        row++;
    }
    
    return SUCCESS;
}

static void findNeighbor(int index, int lastAccessed);

static bool isValidChar(char c)
{
    return (c >= 'a' && c <= 'z') ? true : false;
}

void Table::setVal(int row, int column, char value)
{
    matrix[row + column*dim] = value;
}

char Table::getVal(int row, int column)
{
    return matrix[row + column*dim];
}
