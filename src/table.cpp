//
//  table.cpp
//  boggle
//
//  Created by Josh Laney on 8/26/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "../include/table.hpp"


using namespace std;


/*
 * Name: addTable
 * Purpose: Take a user input table and create an internal matrix
 * Return: SUCCESS or ERROR
 */
int Table::addTable()
{
    /* Verify user input */
    string line;
    int row = 0;
    /* Take in all rows */
    while (row < dim)
    {
        cin >> line;
        /* Take in all columns */
        for (int column = 0; column < dim; column++)
        {
            /* No input validation is necessary */
            setVal(row, column, line[column]);
        }
        /* Skip '\n' */
        cin.ignore();
        
        row++;
    }
    
    return SUCCESS;
} /* function addTable */


/*
 * Name: findAllWords
 * Purpose: Find all words greater than 2 letters in a matrix
 * Return: SUCCESS
 */
int Table::findAllWords()
{
    
    /* Loop through every character in the matrix */
    for (int i = 0; i < dim*dim; i++)
    {
        /* Create new vector and pass it into stringBuilder */
        vector<char> word;

        /* Call stringBuilder on every position in the matrix */
        stringBuilder(word, {i/dim, i%dim});
    }
    
    return SUCCESS;
} /* function findAllWords */


/*
 * Name: stringBuilder
 * Purpose: Obtain all possible strings from a given matrix
 * Parameters: vector<char> word            Holds the characters in the current word
 *                      Coordinates coords           Contains the coordinates of the current letter
 */
void Table::stringBuilder(vector<char> word, Coordinates coords)
{
    /* Add letter to array */
    word.push_back(getVal(coords.row, coords.column));
    
    /* Find all possible next letter jumps */
    vector<Coordinates> all_possible = findNeighbors(coords.row, coords.column);
    
    /* Base case: if there are no other possibilities and it's more than 2 letters long, add it to the word list */
    if (word.size() > 2)
    {
        string str;
        for (auto const& s : word)
            str += s;
        
        word_list.push_back(str);

        if (all_possible.size() == 0)
            return;
    }
    
    /* Call stringBuilder on every valid letter */
    for (int i = 0; i < all_possible.size(); i++)
        stringBuilder(word, all_possible[i]);
} /* function stringBuilder */


/*
 * Name: sorter
 * Purpose: Compare two strings based on length and then alphabetically
 * Parameters: const string& a              First comparison string
 *                      const string& b             Second comparison string
 * Return: true or false
 */
bool Table::sorter(const string& a, const string& b)
{
    if (a.length() < b.length())
        return true;
    else if (a.length() > b.length())
        return false;
    else
        return a < b;
} /* function sorter */


/*
 * Name: print
 * Purpose: Prints all words stored in the word_list
 */
void Table::print()
{
    /* Sort by length alphabetically */
    sort(word_list.begin(), word_list.end(), sorter);
    word_list.erase( unique( word_list.begin(), word_list.end() ), word_list.end() );

    /* Print all words */
    for (int i = 0; i < word_list.size(); i++)
        cout << word_list[i] << endl;
} /* function print */


/*
 * Name: findNeighbors
 * Purpose: Finds all possible neighbors of the current letter. Must be a valid 
 *                 coordinate of a matrix member adjacent to the current letter and 
 *                 must be of greater ASCII value than the current letter.
 * Parameters: int row                  Row of current letter
 *                      int column            Column of current letter
 * Return: a list of all valid coordinates
 */
vector<Coordinates> Table::findNeighbors(int row, int column)
{
    vector<Coordinates> return_list;
    /* Top left */
    if (borderCheck(row-1, column-1) && getVal(row-1, column-1) > getVal(row, column))
        return_list.push_back( { (row-1), (column-1) } );
    
    /* Top above */
    if (borderCheck(row-1, column) && getVal(row-1, column) > getVal(row, column))
        return_list.push_back( { (row-1), column } );
    
    /* Top right */
    if (borderCheck(row-1, column+1) && getVal(row-1, column+1) > getVal(row, column))
        return_list.push_back( { (row-1), (column+1) } );
    
    /* Left */
    if (borderCheck(row, column-1) && getVal(row, column-1) > getVal(row, column))
        return_list.push_back( { row, (column-1) } );
    
    /* Right */
    if (borderCheck(row, column+1) && getVal(row, column+1) > getVal(row, column))
        return_list.push_back( { row, (column+1) } );
    
    /* Bottom left */
    if (borderCheck(row+1, column-1) && getVal(row+1, column-1) > getVal(row, column))
        return_list.push_back( { (row+1), (column-1) } );
    
    /* Bottom below */
    if (borderCheck(row+1, column) && getVal(row+1, column) > getVal(row, column))
        return_list.push_back( { (row+1), column } );
    
    /* Bottom right */
    if (borderCheck(row+1, column+1) && getVal(row+1, column+1) > getVal(row, column))
        return_list.push_back( { (row+1), (column+1) } );
    
    return return_list;
} /* function findNeighbors */
