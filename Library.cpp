//
//  Library.cpp
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Library.hpp"


Library::Library()   //this basically exists to throw the user off.  It's... an empty room.  But they waste a move!
{
    
}


char Library::roomPlay (Hero * player1)  //takes in player
{
    char libraryChoice;  //takes in room choice
    
    cout << "You are in a library!  There doesn't seem to be anything here..." << endl;  //there's nothing.  It's a decoy room
    
    
    while (inputBool == true)  //for validation
    {
        cout << "Would you like to stay in this room (s), or exit (x)? " << endl;  //user choice
        
        cin >> libraryChoice;  //takes in choice
        
        if (libraryChoice == 'x' or libraryChoice == 's')  //validation.  If valid...
        {inputBool = false;}  //end loop
        else
        {  //but if not...
            cout << endl;
            cout << "sorry, invalid input!" << endl;
            cout << endl;
            inputBool = true;  //loop again
            
        }
        
        
    }
    
    inputBool = true;  //switches it back
    
    if (libraryChoice == 'x') //if they want to exit
    {
        direction = 'w';  //send them west, back into the hall
    }
    
    else
    {direction = 'x';}  //otherwise, they can just stay and lose a move.
    
    
    return direction;
}

