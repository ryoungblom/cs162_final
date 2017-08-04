//
//  Play.cpp
//  final
//
//  Created by reuben on 3/21/17.
//  Copyright (c) 2017 reuben. All rights reserved.
//

#include "Play.hpp"

Play :: Play ()  //contstructor
{
    /*
    
     This section takes all of the Space pointers and creates new Spaces for all of them.
     Sets spawn to a new Chamber because that's the type of Space you spawn in, etc.
     
     I create multiples of some:  like wings, or halls.  This is because there are two halls, and two wings, and they share the same properties.  But I needed new ones of each.
     This comes into play when, say, you walk into a hall.  The lights are off, and you have to find the switch.  Once you find it, the lights are on!  So next time you come into THAT hall, the lights are on.  But when you walk into the next hall, the lights are off until you turn them on, because I created two different New halls.
     
    */
    
    finish = new Lab;
    spawn = new Chamber;
    leftCenter = new Hall;
    leftUp = new Storeroom;
    leftDown = new Wing;
    rightCenter = new Hall;
    rightUp = new Corridor;
    rightDown = new Wing;
    keyLab = new Office;
    decoy = new Library;
    
    
    /*
     
     This section is where I linked them all together.  Since all spaces have four pointers, they all have left, right, etc.
     
     So if you're in spawn, it only links to left and right, because those are the only doors.  but halls have doors in every direction, so I linked all four pointers up to the appropriate directions.
     
     */
    
    
    spawn -> left = finish;
    spawn -> right = leftCenter;
    
    finish -> right = spawn;
    
    leftCenter -> left = spawn;
    leftCenter -> right = rightCenter;
    leftCenter -> up = leftUp;
    leftCenter -> down = leftDown;
    
    leftUp -> down = leftCenter;
    
    leftDown -> up = leftCenter;
    
    rightCenter -> left = leftCenter;
    rightCenter -> right = decoy;
    rightCenter -> up = rightUp;
    rightCenter -> down = rightDown;
    
    rightUp -> right = keyLab;
    rightUp -> down = rightCenter;
    
    rightDown -> up = rightCenter;
    
    keyLab -> left = rightUp;
    
    decoy -> left = rightCenter;
    
}


//This (below) actually starts the game. It's basically a loop, and each loop (whether you move to the next room, or affirmitavely decide to stay in your current room) is one "move".  You only have 20 moves.

//Hint for the grader:  See the reflection document for instructions on how to win, if necessary.


bool Play::gameStart (Hero * player1)  //starts game, takes in a Hero pointer (player1)
{
    char nextMove;  //tracks next move (direction)
    int moveTracker = 0;  //tracks how many moves have gone so far
    currentSpace = spawn;  //sets currentSpace to default to spawn (hence the name)
    currentSpaceArrayx = 1;  //initializes array dims to "spawn" (on map)
    currentSpaceArrayy = 1;

    
    while (moveTracker < 15)  //loop ends when moveTracker gets to 15 moves
    {
        
        cout << "You have made: " << moveTracker << " moves!" << endl;  //tells user how many moves they've made
        
        printMap(currentSpaceArrayx, currentSpaceArrayy);  //prints out a primative map for the user to get some sense of where they are

        
        nextMove = currentSpace->roomPlay(player1);  //directs what the next move is.  Which char dicates which space is linked to next
        
        if (nextMove == 'e')
        {
            currentSpace = currentSpace -> right;  //i.e. if 'e' was an option and was chosen, links to the right
            
            currentSpaceArrayx = currentSpaceArrayx + 1;  //and moves map character to the right one
            
        }
        
        if (nextMove == 'w')  //same with w -> moves to the left (west)
        {
            currentSpace = currentSpace -> left;
            currentSpaceArrayx = currentSpaceArrayx - 1;  //and moves the map
        }
        
        if (nextMove == 'n') //and so on for north
        {
            currentSpace = currentSpace -> up;
            currentSpaceArrayy = currentSpaceArrayy - 1;
        }
        
        if (nextMove == 's')  //and south
        {
            currentSpace = currentSpace -> down;
            currentSpaceArrayy = currentSpaceArrayy + 1;
        }
        
        
        if (nextMove == 'x')  //when the user wants to stay in a room and makes that affirmative choice, I still wanted to register a move
        {
            currentSpace = currentSpace;  //so if the choose to stay, sends back an 'x' and they stay put but lose a move.
        }
        
        if (nextMove == 'v')  //if a 'v' comes back, they are victorious and the loops ends, and they win!
        {
            gameWon = true;  //it kicks back true to main.cpp, which registers a win.
            
            break;}  //and ends the loop
        
        moveTracker ++;  //adds one to the moves
        
    }

    //after all loops exit, free up memory to avoid memory leaks
    
    delete finish;
    delete spawn;
    delete leftCenter;
    delete leftUp;
    delete leftDown;
    delete rightCenter;
    delete rightUp;
    delete rightDown;
    delete keyLab;
    delete decoy;
    
    return gameWon;  //will return false unless user has won
}






void Play::printMap (int csX, int csY)  //this prints the map.  It creates an array of the space
{
    
    char mapArray [3][5];
    
    
    //and initilizes spaces where there are rooms to char 'O'
    mapArray [1][0] = 'O';
    mapArray [1][1] = 'O';
    mapArray [0][2] = 'O';
    mapArray [1][2] = 'O';
    mapArray [2][2] = 'O';
    mapArray [0][3] = 'O';
    mapArray [1][3] = 'O';
    mapArray [2][3] = 'O';
    mapArray [0][4] = 'O';
    mapArray [1][4] = 'O';
    
    mapArray [0][0] = ' ';  //and the rest to be blank
    mapArray [0][1] = ' ';
    mapArray [2][4] = ' ';
    mapArray [2][0] = ' ';
    mapArray [2][1] = ' ';
    
    
    mapArray [csY][csX] = '*';  //then, it takes the user's position and puts an '*'
    
    cout << endl;
    cout << endl;
    
    cout << "You are here:" << endl;  //and tells the user that they are looking at a map
    cout << endl;
    
    for (int i = 0; i < 3; ++i)  //prints map
    {
        for (int j = 0; j < 5; ++j)
        {
            cout << mapArray[i][j] << ' ';
        }
        cout << endl;
    }
    
    cout << endl;
}


