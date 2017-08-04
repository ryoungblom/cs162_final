//
//  Space.cpp
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Space.hpp"


Space::Space ()  //contructor.  initializes unused pointers to NULL
{
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
}

char Space::roomPlay(Hero * player1)  //empty function to make class abstract (used Virtual for prototype)
{
    return ' ';
}

