//
//  Library.h
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Office.hpp"

class Library : public Space
{
public:
    Library ();
    char roomPlay(Hero * player1);  //normal roomPlay function calls the room
};

