//
//  Play.h
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Library.hpp"


class Play  //this class is what actually runs the game.  Doing it this way means that variables will stay consistent within each game, but will change from game to game.
{
private:
    
    Space * finish;  //the antidode is in here
    Space * spawn; //starting point
    Space * leftCenter;  //left center hall
    Space * leftUp;  //upper left Hall
    Space * leftDown;  //lower left hall
    Space * rightCenter;  //right center hall
    Space * rightUp;  //upper right hall
    Space * rightDown;  //lower right hall
    Space * keyLab;  //this lab is only attached to the upper right hall. It holds the key
    Space * decoy;
    
    Space * currentSpace;  //tracks the current space

    Hero * player1;  //player1 is a hero pointer
    
public:
    Play ();  //prototype
    bool gameStart (Hero * player1);  //plays the game
    int currentSpaceArrayx;  //tracks x dim of map
    int currentSpaceArrayy;  //tracks y dim of map
    void printMap (int, int);  //prints the map, takes x and y dims
    bool gameWon = false;  //tracks whether game has been won or lost
};

