//
//  main.cpp
//  boggle
//
//  Created by Josh Laney on 8/26/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include <iostream>
#include "base.hpp"
#include "table.hpp"

using namespace std;


int main(int argc, const char * argv[]) {
    /* Take user input for number of cases */
    /* Design choice: use an int and check for negative values explicitly rather than using an uint and casting
                                a negative to 2's compliment.
     */
    int num_of_cases;
    if (!(cin >> num_of_cases))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"You must enter the number of cases to follow.\n";
        return ERROR;
    }
    else if (num_of_cases < 0)
    {
        cout << "You must enter a non negative amount of cases.\n";
        return ERROR;
    }
    else if (num_of_cases == 0)
        return SUCCESS;
    
    /* Take in blank line */
    cin.ignore();
    if (cin.get() != '\n')
    {
        cout << "You must enter a blank line following the number of cases.\n";
        return ERROR;
    }
    
    vector<Table> tables;
    while (num_of_cases > 0) {
        /* Take in N, the size of the matrix */
        int dimension;
        if (!(cin >> dimension))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"You must enter the number of characters on each side of the table.\n";
            return ERROR;
        }
        else if (dimension < 0 || dimension > 20)
        {
            cout << "You must enter a non negative dimension between 0 and 20.\n";
            return ERROR;
        }
        else if (dimension == 0)
            //TODO: handle this case
            return SUCCESS;
    
        /* Take in the matrix */
        cin.ignore();
        Table t = Table(dimension);
    
        if (t.addTable() != SUCCESS)
            return ERROR;
    
        /* Find the words */
        if (t.findAllWords() != SUCCESS)
            return ERROR;
        
        /* Add table to vector */
        tables.push_back(t);
        
        num_of_cases--;
    }
    
    /* Print all tables */
    for (int i = 0; i < tables.size(); i++) {
        cout << endl;
        tables[i].print();
    }
    return 0;
}
