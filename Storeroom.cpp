//
//  Storeroom.cpp
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Storeroom.hpp"


Storeroom::Storeroom ()  //constructor
{
    
}

char Storeroom::roomPlay(Hero * player1)  //this is where the password book is found
{
    char storeRoomChoice;  //for all room choices
    
    cout << "You are in a Storeroom! " << endl;
    
    
    while (inputBool == true)  //input validation loop
    {
        
        cout << "Would you like to look around?  (y/n): " << endl;  //do they want to look around?
        
        cin >> storeRoomChoice;  //user input
        
        
        
        if (storeRoomChoice == 'y' or storeRoomChoice == 'n')  //validation.  If valid...
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
    
    
    
    if (storeRoomChoice == 'y')   //if they want to look around
    {
        
        if (passwordBool == false)   //if they ahven't found the password book yet....
        {

            while (inputBool == true)  //IV loop
            {
                cout << "There is a book of passwords on the shelf!  Would you like to grab it? (y/n)" << endl;
                
                cin >> storeRoomChoice;  //user input
                
                if (storeRoomChoice == 'y' or storeRoomChoice == 'n')  //validation.  If valid...
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
            
            if (storeRoomChoice == 'y')  //if they want to grab it
            {
                
                itemCounter = player1->Pockets.size();  //check inventory size
                
                
                if (itemCounter < 1)  //if it's empty
                {
                    

                    cout << "You grabbed the book of passwords and put it in your bag!" << endl;  //they can grab the password book
                    
                    player1 -> havePassword = true;  //they now have the password
                    
                    passwordBool = true;  //and the book won't show up any more
                    
                    player1->Pockets.push_back(1);  //and inventory has grown
                    
                }
                
                else //if inventory is too big
                {
                    cout << "Sorry! Your bag is full!" << endl;
                    
                    
                    while (inputBool == true)   //IV loop
                    {
                        
                        cout << "Would you like to take the candle out of your bag and take the passwords, instead? (y/n)" << endl;
                        
                        cin >> storeRoomChoice;  //user input
                        
                        if (storeRoomChoice == 'y' or storeRoomChoice == 'n')  //validation.  If valid...
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
                    
                    if (storeRoomChoice == 'y')  //if they choose to dump it
                    {
                        player1 -> removeInventory();  //clear inventory
                        
                        cout << "You dumped the candle out the window, and placed the book of passwords in your bag!" << endl;
                        
                        player1 -> havePassword = true;  //they now have the password
                        
                        passwordBool = true;  //and the book will never be back
                        
                        player1->Pockets.push_back(1);  // and their inventory is full
                    }
                    
                    else
                    {
                        
                    }
                    
                }
            }
            
        }
        
        
        
        else  //if they've already had password book, room is empty!
        {
            cout << "There doesn't seem to be anything here!" << endl;
        }
        
   
    }
    
    
    while (inputBool == true)  //IV loop
    {
        
        cout << "Would you like to stay in this room (s), or exit (x)? " << endl;
        
        cin >> storeRoomChoice;  //user info
        
        if (storeRoomChoice == 's' or storeRoomChoice == 'x')  //validation.  If valid...
        {inputBool = false;}  //end loop
        else
        {  //but if not...
            cout << endl;
            cout << "sorry, invalid input!" << endl;
            cout << endl;
            inputBool = true;  //loop again
            
        }
        
    }
    
    
    inputBool = true;   //reset bool for later
    
    if (storeRoomChoice == 'x')  //if they want to exit, send them south to the hall
    {
        direction = 's';
    }
    
    else
    {direction = 'x';}  //or they can stay and lose a move

    
    return direction;
}
