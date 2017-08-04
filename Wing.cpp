//
//  Wing.cpp
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Wing.hpp"

Wing :: Wing ()  //constructor
{
    
}

char Wing::roomPlay(Hero * player1)  //takes in player1
{
    char wingChoice;  //for all room choices
    
    cout << "You are in a Wing!  The only door here is the door you just came out of, to the north." << endl;  //user info
    
    
    while (inputBool == true)  //input validation loop
    {
        
        cout << "Would you like to look around?  (y/n): " << endl;  //do they want to look around?
        cin >> wingChoice;  //user choice
        
        if (wingChoice == 'y' or wingChoice == 'n')  //validation.  If valid...
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
    if (wingChoice == 'y')  //if they want to look around, and if they haven't found a candle in either wing yet....
    {
 
        if (candleBool == false)
        {

            while (inputBool == true)   //input validation loop
            {
                
                /*
                 
                 NOTE: this candle is a decoy object.  The hope is that the user will waste time/moves grabbing it, either after they get the passwords but before they use them, or after they get the key but before they use them, thus ensuring their death.
                 
                 */
                
                cout << "There is a candle on the shelf!  Would you like to grab it? (y/n)" << endl;  //they found a candle and can grab it!
                
                cin >> wingChoice;  //user choice
                
                if (wingChoice == 'y' or wingChoice == 'n')  //validation.  If valid...
                {inputBool = false;}  //end loop
                else
                {  //but if not...
                    cout << endl;
                    cout << "sorry, invalid input!" << endl;
                    cout << endl;
                    inputBool = true;  //loop again
                    
                }
  
            }
            
            inputBool = true;  //resets bool for later
            
            if (wingChoice == 'y')  //if they want to grab it
            {
                
                itemCounter = player1->Pockets.size();  //check vector size
                
                if (itemCounter < 1)  //if the bag is empty....
                {
                    
                    cout << "You grabbed the candle and put it in your bag!" << endl;  //grab candle!
                    
                    candleBool = true;  //now it won't appear in either wing
                    
                    player1->addInventory();  //and add to vector
                }
                
                else  //but if bag has something in it
                {
                    cout << "Sorry! Your bag is full!" << endl;
                    
                    
                    while (inputBool == true)  //input validation loop
                    {
                        
                        cout << "Would you like to empty your bag and take the candle instead?" << endl;
                        
                        cin >> wingChoice;  //user input
                        
                        if (wingChoice == 'y' or wingChoice == 'n')  //validation.  If valid...
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
                    
                    if (wingChoice == 'y')  //if they want to empty their bag
                    {
                        player1 -> removeInventory();  //run remove function to pop item
                        
                        cout << "You dumped the contents of your bag out the window, and placed the candle in your bag!" << endl;
                        
                        player1 -> havePassword = false;  //if they have ever had the password, now they lost it.  It's gone forever
                        player1 -> haveKey = false;  //simliarly, they will lose the key forever
                        
                        candleBool = true;  //now the candle won't appear in either wing
                        
                        player1->Pockets.push_back(1);  //add to vector
                    }

                }
            }
            
        }
        
        
        
        else  //but if candle has been found in either wing...
        {
            cout << "There doesn't seem to be anything here!" << endl;  //room is empty
        }

    }
    
    
    
    while (inputBool == true)   //input validation loop
    {
        
        cout << "Would you like to stay in this room (s), or exit (x)? " << endl;
        
        cin >> wingChoice;  //user input
        
        if (wingChoice == 's' or wingChoice == 'x')  //validation.  If valid...
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
    
    if (wingChoice == 'x')  //if they want to exit
    {
        direction = 'n';  //send them north, to hall
    }
    
    else
    {direction = 'x';}  //or they can stay and lose a move
    
    return direction;
}

