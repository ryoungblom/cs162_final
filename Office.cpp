//
//  Office.cpp
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//


#include "Office.hpp"


Office::Office ()  //constructor
{
    
}

char Office::roomPlay(Hero * player1)    //takes in player to "put" in office
{
    char officeChoice;  //for user choice
    
    cout << "You are in an office." << endl;  //user info
    

    while (inputBool == true)  //input validation
    {
        cout << "Would you like to look around?  (y/n): " << endl;  //do they want to look around?  They can choose no.

        cin >> officeChoice;  //takes in choice
        
        if (officeChoice == 'y' or officeChoice == 'n')  //validation.  If valid...
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
    
    if (officeChoice == 'y')  //so, if they want to look around...
    {
        
        
        if (keyBool == false)   //if they don't have the key already....
        {
            
            
            while (inputBool == true)   // input validation
            {
                
                cout << "There is a key on the desk!  Would you like to grab it? (y/n)" << endl;   //there's a key!  cool!
                
                cin >> officeChoice;  //do they want to grab it?
                
                if (officeChoice == 'y' or officeChoice == 'n')  //validation.  If valid...
                {inputBool = false;}  //end loop
                else
                {  //but if not...
                    cout << endl;
                    cout << "sorry, invalid input!" << endl;
                    cout << endl;
                    inputBool = true;  //loop again
                    
                }
                
                
                
            }
            
            inputBool = true;  //resets bool for next time
            
            if (officeChoice == 'y')  //if they do....
            {
                
                itemCounter = player1->Pockets.size();   //puts it into their bag
                
                if (itemCounter < 1)  //...as long as theur bag is empty
                {
                    
                    cout << "You grabbed the key and put it in your bag!" << endl;
                    
                    keyBool = true;  //if so, makes the keyBool true so the key is "gone" next time
                    player1 -> haveKey = true;  //and gives them the key
                    
                    player1->addInventory();  //and adds to their inventory
                }
                
                else
                {
                    cout << "Sorry! Your bag is full!" << endl;  //but if they already have something in their bag, it's full!
                    
                    
                    while (inputBool == true)  //input validation
                    {
                        
                        cout << "Would you like to empty your bag and take the key, instead? (y/n)" << endl;  //gives them the option of dumping their bag
                        
                        cin >> officeChoice;  //user input
                        
                        if (officeChoice == 'y' or officeChoice == 'n')  //validation.  If valid...
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
                    
                    if (officeChoice == 'y')  //if they dump it
                    {
                        player1 -> removeInventory();   // their inventory shrinks
                        
                        cout << "You dumped your bag out the window, and placed the key in your bag!" << endl;
                        
                        
                        player1 -> havePassword = false; //now they don't have the password anymore
                        keyBool = true;  //the key is "gone"
                        player1 -> haveKey = true;  //and they "have" it
                        
                        player1->Pockets.push_back(1);  //and now their inventory is full again
                    }
 
                }
            }
            
        }
        
        
        
        else
        {
            cout << "There doesn't seem to be anything here!" << endl;  //if no key (if they already have it), the room is empty!
        }
    }
    
    
    
    while (inputBool == true)  //input validation
    {
        
        cout << "Would you like to stay in this room (s), or exit (x)? " << endl;  //at the end of their "turn" in this room, ask what they want to do
        
        cin >> officeChoice;  //user input
        
        if (officeChoice == 's' or officeChoice == 'x')  //validation.  If valid...
        {inputBool = false;}  //end loop
        else
        {  //but if not...
            cout << endl;
            cout << "sorry, invalid input!" << endl;
            cout << endl;
            inputBool = true;  //loop again
            
        }
        
        
        
    }
    inputBool = true;  //resets for later
    
    
    if (officeChoice == 'x')  //if they want to leave,
    {
        direction = 'w';  //send them west into Corridor
    }
    
    else
    {direction = 'x';}  //or else they can stay.
    
    return direction;
}

