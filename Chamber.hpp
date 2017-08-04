//
//  Chamber.h
//  final
//
//  Created by reuben on 3/20/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Space.hpp"


class Chamber : public Space
{
public:
    Chamber ();  //prototype
    char roomPlay(Hero * player1);  //room Function
    int blockedDoor = 5;  //tracks which door is blocked by the desk
    
};
