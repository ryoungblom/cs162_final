//
//  Chamber.cpp
//  final
//
//  Created by reuben on 3/20/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Chamber.hpp"



Chamber::Chamber () : Space ()  //constructor
{
    
}


char Chamber::roomPlay (Hero * player1)  //roomPlay function. Takes in Hero pointer
{
    char chamberChoice;  //for all chamber choices
    char goThroughDoor;  //this was originally an int, so the coding it a little seperate.  Doesn't need to be.
    
    cout << "You are in the Chamber." << endl;
    
    cout << endl;
    
    if (blockedDoor == 5)  //determines which door is blocked by the desk.  Default is that the lab door is unblocked, and the door to the rest of the map is blocked.
    {
        cout << "To the west is the door to the lab, and to the east is a door hidden behind a large desk." << endl;
        
        while (inputBool == true) //IV loop
        {
            cout << "Would you like to push the desk across the room (p), or go through the door (w)?" << endl;
            
            cin >> chamberChoice;  //user input
            
            if (chamberChoice == 'p' or chamberChoice == 'w')  //validation.  If valid...
            {inputBool = false;}  //end loop
            else
            {  //but if not...
                cout << endl;
                cout << "sorry, invalid input!" << endl;
                cout << endl;
                inputBool = true;  //loop again
                
            }
        }
        
        cout << endl;
        
        inputBool = true;  //resets bool for later
        
        
        switch (chamberChoice)  //which would the user like to do?
        {
            case 'p':  //if they want to push the desk across the room
            {
                //the lab door is blocked, but the other door is open
                cout << "You push the desk across the room.  Now, the door on the west is hidden by the desk, and the door on the east is open." << endl;
                blockedDoor = 6;  //and tracker switches
                
                
                while (inputBool == true)  //IV loop
                {
                    
                    cout << "Would you like to go through the door?  (y/n): " << endl;
                    cin >> goThroughDoor;  //user input for new choice
                    
                    if (goThroughDoor == 'y' or goThroughDoor == 'n')  //validation.  If valid...
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
                
                if (goThroughDoor == 'y')  //if they want to go through the door
                {direction = 'e';}  //send them East to the rest of the map
                
                break;
            }
                
            case 'w':  //but if not, do they have the key?
            {
                if (player1 -> haveKey == false)  //if not
                {
                    cout << endl;  //door is locked!
                    cout << "It's locked! You'll have to find the key!" << endl;
                    cout << endl;
                }
                
                else  //if they have the key...
                {
                    cout << endl;  //it opens!
                    cout << "It opens!  You go into the next room..." << endl;
                    cout << endl;
                    direction = 'w';  //so they can go west, into the lab
                }
                break;
            }
        }
        

    }
    
 
    
    
    else if (blockedDoor == 6)  //but if the lab door is the one blocked....
    {
        
        
        cout << "To the west is the door to the lab, but it's hidden behind a large desk. To the east is a doorway." << endl;
        
        
        while (inputBool == true)  //IV loop
        {

            cout << "Would you like to push the desk across the room (p), or go through the door (e)?" << endl;
            
            cin >> chamberChoice;  //user choice input
            
            
            if (chamberChoice == 'p' or chamberChoice == 'e')  //validation.  If valid...
            {inputBool = false;}  //end loop
            else
            {  //but if not...
                cout << endl;
                cout << "sorry, invalid input!" << endl;
                cout << endl;
                inputBool = true;  //loop again
                
            }
            
        }
        
        cout << endl;
        inputBool = true;  //resets bool
        
        switch (chamberChoice)  //takes in choice
        {
            case 'p':  //if they want to push the desk...
            {
                cout << endl;  //the lab door is clear and the door to the rest of the map is blocked off
                cout << "You push the desk across the room.  Now, the door on the east is hidden by the desk, and the door to the lab is clear." << endl;
                blockedDoor = 5;  //and tracker switches
                direction = 'x';  //and they stay put
                
                
                break;
            }
                
            case 'e':  //but if they want to go east
            {
                
                cout << "You go through the doorway!" << endl;
                
                direction = 'e';  //they go east
                
                break;
            }
        }
        
    }
    
    
    
    return direction;
}




