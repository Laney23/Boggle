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
    
    /* Call stringBuilder on every valid letter */
    for (int i = 0; i < all_possible.size(); i++)
        stringBuilder(word, all_possible[i]);
}


bool Table::sorter(const string& a, const string& b)
{
    if (a.length() < b.length())
        return true;
    else if (a.length() > b.length())
        return false;
    else
        return a < b;
}


void Table::print()
{
    /* Sort by length alphabetically */
    sort(word_list.begin(), word_list.end(), sorter);

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


