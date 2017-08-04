//
//  Hall.cpp
//  final
//
//  Created by reuben on 3/20/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Hall.hpp"

Hall::Hall () : Space ()  //prototype
{
    
}


char Hall::roomPlay(Hero * player1)  //room function.  Takes in Hero pointer
{
    
    cout << endl;
    cout << "You are in a Hall" << endl;  // user info
    
    if (lightSwitch == false)  //if lights haven't been turned on yet....
    {
        
        char throwAway;  //for recording input.  I named it throwaway because I knew the first input would never matter because the lights are off, but then I used it again a few times but kept the name.

        
        while (inputBool == true)  //IV loop
        {
            cout << endl;

            cout << "Which direction would you like to move? (n/s/e/w):" << endl;  //decoy question.  Doesn't matter, the lights are off!

            cout << endl;
            
            cin >> throwAway;  //takes in input but doesn't do anythign with it
            
            if (throwAway == 'n' or throwAway == 'e' or throwAway == 'w' or throwAway == 's')  //validation.  If valid...
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

        
        cout << "Oh, no!  It's so dark in here, you can't see where you're going.  Better find a lightswitch..." << endl;
        
        cout << endl;
        
        while (keepFlipping == false)  //until they find the lightswitch...
        {
            
            while (inputBool == true)  //IV loop
            {

                cout << "Which wall would you like to check for a switch (e/w/n/s)?" << endl;
                
                
                cin >> throwAway;  //takes in wall guess
                
                
                if (throwAway == 'n' or throwAway == 'e' or throwAway == 'w' or throwAway == 's')  //validation.  If valid...
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
            
            
            if (throwAway == 's') //if they guess south (for either Hall, doesn't matter)
            {
                lightSwitch = true;  //the lights turn on
                
                cout << endl;
                
                cout << "Great! You found the switch!  You can see! There are four doors, one in every direction." << endl;
                keepFlipping = true;  //and loop ends
            }
            
            else  //but any other guess....
            {
                cout << "Sorry! Not on this wall.  Try again!" << endl;
            }
            
            
        }
        
    }
    
    
    
    else  //but if lights are already on....
    {
        cout << endl;
        cout << "The lights are already on, so you can see your options!" << endl;  //they can see!
    }
    
    
    while (inputBool == true)  //IV loop
    {

        cout << endl;
        cout << "Which door would you like to go through? (n/s/e/w): " << endl;
        
        
        cin >> direction;  //user input.  But this time, take the direction they want to go in Directly, because it can by anything.
        
        if (direction == 'w' or direction == 'e' or direction == 's' or direction == 'n')  //validation.  If valid...
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
    
    return direction;
}


