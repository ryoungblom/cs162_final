//
//  Lab.h
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Hall.hpp"

class Lab : public Space
{
public:
    Lab ();
    char roomPlay(Hero * player1);  //roomPlay function, for running room.  Takes in Hero pointer
    bool labBox;  //this never got used, but I'm scared to delete it because I coded it so long ago and what if it crashes my program?  It's not hurting anything just sitting there.
};
