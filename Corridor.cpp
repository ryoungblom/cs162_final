//
//  Corridor.cpp
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//


#include "Corridor.hpp"


Corridor::Corridor()  //constructor
{
    
}

char Corridor::roomPlay(Hero * Player1)  //takes in player1
{
    char cordChoice;  //for all choices in this room
    
    cout << "You are in a corridor!" << endl;  //user info
    cout << "There is a door to your south, and a door to your east" << endl;
    
    
    while (inputBool == true)  //input validation
    {
        
        cout << "Which door would you like to try? (s/e)" << endl;  //user info
        
        cin >> cordChoice;  //takes in info
        
        if (cordChoice == 's' or cordChoice == 'e')  //validation.  If valid...
        {inputBool = false;}  //end loop
        else
        {  //but if not...
            cout << endl;
            cout << "sorry, invalid input!" << endl;
            cout << endl;
            inputBool = true;  //loop again
            
        }
        
        
        
    }
    
    inputBool = true;
    
    if (cordChoice == 's')  //if they try the south door, they just exit to the south
    {
        direction = 's';
    }
    
    else  //but if they try the east door...
    {
        if (Player1 -> havePassword == true)  //if they have the password....
        {
            cout << endl;
            cout << "This door takes a password, but you have the password book! The door opens" << endl;  //they get in!
            direction = 'e';  //and go east
        }
        
        
        else
        {
            cout << "Sorry!  This door takes a password.  You need to find the password!" << endl;  //but if not, they are denied access, and the room starts over
            direction = 'x';
        }
        
    }
    
    
    
    
    return direction;
}
