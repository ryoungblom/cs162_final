//
//  Hero.h
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Hero  //hero class to create the player
{
    
private:
    
public:
    Hero ();  //prototype
    vector <int> Pockets;  //inventory vector.  Was originally going to be pockets, but turned into a bag later.  Name still stuck.
    void addInventory();  //adds item counter to vector
    void removeInventory();  //removes item counter from vector
    bool havePassword = false;  //determines if user has found password book yet (and hasn't dumped it)
    bool haveKey = false;  //determines if user has found key yet (and hasn't dropped it)
    
};
