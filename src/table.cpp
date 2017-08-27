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
static char findNeighbor(int row, int column);
static bool borderCheck(int row, int column, int dim);


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
    
    /* Initialize all values to unseen */
    resetTable();
    
    return SUCCESS;
}

char Table::findNeighbor(int row, int column)
{
    if (borderCheck(row-1, column-1, dim) && matrix[(row-1)+(column-1)*dim].seen == false)
    {
        matrix[(row-1)+(column-1)*dim].seen = true;
        return matrix[(row-1)+(column-1)*dim].c;
    }
    else if (borderCheck(row-1, column, dim) && matrix[(row-1)+column*dim].seen == false)
    {
        matrix[(row-1)+column*dim].seen = true;
        return matrix[(row-1)+column*dim].c;
    }
    else if (borderCheck(row-1, column+1, dim) && matrix[(row-1)+(column+1)*dim].seen == false)
    {
        matrix[(row-1)+(column+1)*dim].seen = true;
        return matrix[(row-1)+(column+1)*dim].c;
    }
    else if (borderCheck(row, column-1, dim) && matrix[row+(column-1)*dim].seen == false)
    {
        matrix[row+(column-1)*dim].seen = true;
        return matrix[row+(column-1)*dim].c;
    }
    else if (borderCheck(row, column+1, dim) && matrix[row+(column+1)*dim].seen == false)
    {
        matrix[row+(column+1)*dim].seen = true;
        return matrix[row+(column+1)*dim].c;
    }
    else if (borderCheck(row+1, column-1, dim) && matrix[(row+1)+(column-1)*dim].seen == false)
    {
        matrix[(row+1)+(column-1)*dim].seen = true;
        return matrix[(row+1)+(column-1)*dim].c;
    }
    else if (borderCheck(row+1, column, dim) && matrix[(row+1)+column*dim].seen == false)
    {
        matrix[(row+1)+column*dim].seen = true;
        return matrix[(row+1)+column*dim].c;
    }
    else if (borderCheck(row+1, column+1, dim) && matrix[(row+1)+(column+1)*dim].seen == false)
    {
        matrix[(row+1)+(column+1)*dim].seen = true;
        return matrix[(row+1)+(column+1)*dim].c;
    }
    
    /* If no unseen neighbors, return the character 1 */
    return '1';
}

static bool borderCheck(int row, int column, int dim)
{
    return (row >= 0 && row <= dim && column >= 0 && column < dim);
}

static bool isValidChar(char c)
{
    return (c >= 'a' && c <= 'z') ? true : false;
}

void Table::setVal(int row, int column, char value)
{
    matrix[row + column*dim].c = value;
}

char Table::getVal(int row, int column)
{
    return matrix[row + column*dim].c;
}

void Table::resetTable()
{
    for (int i = 0; i < dim*dim; i++)
        matrix[i].seen = false;
}
