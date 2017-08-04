//
//  Office.h
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Corridor.hpp"

class Office : public Space
{
public:
    Office ();
    char roomPlay (Hero * player1);  //normal roomPlay function calls the room
};
