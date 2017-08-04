//
//  Space.h
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Hero.hpp"


class Space : public Hero  //abstract class, but friend to Hero
{
private: //nothing here, my functions are all friends.  Cute.
protected:
    char direction;  //blanket variable for user directions
public:
    Space ();
    virtual char roomPlay(Hero * player1);  //used for all rooms.  Made virtual so Space would be an abstract class
    string spaceName;  //didn't end up using, but might add later and it's not hurting anything to leave it
    Space * up;  //pointers for all spaces to link.  All of these are used at least once
    Space * down;
    Space * left;
    Space * right;
    int itemCounter;  //was going to use for vector, but switched.  Since this is the final and things work, I'm afraid to delete things, and this isn't hurting anything....
    bool inputBool = true;  //used for Input Validation (IV)
    
    //individual bits....
    
    bool haveKey = false;  //holds whether user has the key or not
    bool candleBool = false;  //i put this up here so that it would run for whichever wing is entered first, but not in the second wing
    bool keyBool = false; //same with the key bool
};
