//
//  Hall.h
//  final
//
//  Created by reuben on 3/20/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Chamber.hpp"


class Hall : public Space
{
public:
    Hall ();
    bool lightSwitch = false;   //this is room-specific.  I want each new Hall to have it's own lights status.
    char roomPlay(Hero * player1);
    bool keepFlipping = false;  //tracks whether or not they found the lightswitch yet
};

