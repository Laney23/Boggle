//
//  main.cpp
//  boggle
//
//  Created by Josh Laney on 8/26/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include <iostream>
#include "base.hpp"

using namespace std;


int main(int argc, const char * argv[]) {
    int num_of_cases;
    if (!(cin >> num_of_cases))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"You must enter the number of cases to follow";
        return ERROR;
    }
    
    
    
    cout << "Hello, World!\n";
    return 0;
}
