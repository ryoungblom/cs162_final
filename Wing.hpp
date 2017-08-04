//
//  Wing.h
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Storeroom.hpp"

class Wing : public Space
{
public:
    Wing ();  //prototype
    char roomPlay (Hero * player1);  //roomPlay function, takes a Hero pointer
};

