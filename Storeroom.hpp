//
//  Storeroom.h
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//


#include "Lab.hpp"

class Storeroom : public Space
{
    
public:
    Storeroom();
    char roomPlay (Hero * player1);  //roomPlay.  Takes in Hero pointer
    bool passwordBool = false;  //tracks whether passwords have been found yet.  Room-specific, so bool goes here
    
};
