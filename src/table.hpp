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
    int dimension;
    
public:
    Table(int d) { dimension = d; }
    int addTable();
};

#endif /* table_hpp */
