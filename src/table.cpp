//
//  table.cpp
//  boggle
//
//  Created by Josh Laney on 8/26/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "table.hpp"

using namespace std;


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


int Table::findAllWords()
{
    
    /* Loop through every character in the matrix */
    for (int i = 0; i < dim*dim; i++) {
        /* Create new vector and pass it into stringBuilder */
        vector<char> word;

        /* Call stringBuilder on every position in the matrix */
        stringBuilder(word, {i/dim, i%dim});

        resetTable();
    }
    
    return SUCCESS;
}


void Table::stringBuilder(vector<char> word, Coordinates coords)
{
    /* Add letter to array */
    word.push_back(getVal(coords.row, coords.column));
    
    /* Find all possible next letter jumps */
    vector<Coordinates> all_possible = findNeighbors(coords.row, coords.column);
    
    /* if the end of the word has been found and it's more than 2 letters long, add it to the word list */
    if (all_possible.size() == 0 && word.size() > 2)
    {
        string str;
        for (auto const& s : word)
            str += s;
        
        word_list.push_back(str);

        return;
    }
    
    for (int i = 0; i < all_possible.size(); i++)
        stringBuilder(word, all_possible[i]);
}


bool sorter(const string& a, const string& b)
{
    return ((a.size() < b.size()) );
}


void Table::print()
{
    /* Sort by length alphabetically */
    struct compare {
        bool operator()(const std::string& first, const std::string& second) {
            return first.size() < second.size();
        }
    };
    compare c;
    sort(word_list.begin(), word_list.end());
    stable_sort(word_list.begin(), word_list.end(), c);
    
    /* Print all words */
    for (int i = 0; i < word_list.size(); i++)
        cout << word_list[i] << endl;
}


vector<Coordinates> Table::findNeighbors(int row, int column)
{
    vector<Coordinates> return_list;
    if (borderCheck(row-1, column-1) && getVal(row-1, column-1) > getVal(row, column))
        return_list.push_back( { (row-1), (column-1) } );
    
    if (borderCheck(row-1, column) && getVal(row-1, column) > getVal(row, column))
        return_list.push_back( { (row-1), column } );
    
    if (borderCheck(row-1, column+1) && getVal(row-1, column+1) > getVal(row, column))
        return_list.push_back( { (row-1), (column+1) } );
    
    if (borderCheck(row, column-1) && getVal(row, column-1) > getVal(row, column))
        return_list.push_back( { row, (column-1) } );
    
    if (borderCheck(row, column+1) && getVal(row, column+1) > getVal(row, column))
        return_list.push_back( { row, (column+1) } );
    
    if (borderCheck(row+1, column-1) && getVal(row+1, column-1) > getVal(row, column))
        return_list.push_back( { (row+1), (column-1) } );
    
    if (borderCheck(row+1, column) && getVal(row+1, column) > getVal(row, column))
        return_list.push_back( { (row+1), column } );
    
    if (borderCheck(row+1, column+1) && getVal(row+1, column+1) > getVal(row, column))
        return_list.push_back( { (row+1), (column+1) } );
    
    return return_list;
}


bool Table::borderCheck(int row, int column)
{
    return (row >= 0 && row < dim && column >= 0 && column < dim);
}


bool Table::isValidChar(char c)
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

