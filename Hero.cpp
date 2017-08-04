//
//  Hero.cpp
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Hero.hpp"


Hero::Hero ()  //constructor
{
    
}

void Hero::addInventory()  //Hero only needs an inventory add function
{
    
    Pockets.push_back(1);  //adds '1' to inventory vector
}

void Hero::removeInventory()  //and pop (remove) function
{
    Pockets.pop_back();  //removes '1' from inventory vector
}

