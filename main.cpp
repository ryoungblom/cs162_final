
#include "Play.hpp"

int main()

{
    bool victory;  //records whether or not the user has won.  Game could end with a win or a loss
    bool Again = true;  //records whether the user wants to play again
    bool validate = true;  //input validation for whether user wants to play or exit
    char userPlay;  //input for whether user wants to play or exit
    
    
    cout << "Welcome to the game! Would you like to play or exit?" << endl;  //user menu.  user can play or exit
    
    while (validate == true)  // input validation loop
    {
        
        cout << "Select (1) to play, or (2) to exit" << endl;  //user menu
        
        cin >> userPlay;  //takes in input
        
        if (userPlay == '1' or userPlay == '2')  //validation.  If valid...
        {validate = false;}  //end loop
        else
        {  //but if not...
            cout << endl;
            cout << "sorry, invalid input!" << endl;
            cout << endl;
            validate = true;  //loop again
            
        }
        
    }
    
    validate = true;  //switches bool back so that it loops next time
    
    
    switch (userPlay)  //uses input to select course of action
   
    {
        case '1':
        {Again = true;  //if they select that they want to play, this "resets" the bool to true.  this basically does nothing.
            break;
        }
            
        case '2':
        {
            Again = false;  //but if not, it sets it to false and the loop with the game doesn't even run.
            break;
        }
    }
    
    while (Again == true)  //if again is true (i.e. if the user hasn't indicated that they want to exit), program loops and runs
        
    {
    
        
        //user info.
        cout << endl;
        cout << endl;
    cout << "Oh, no!  You are in a chamber, and you've been poisoned. Better find a way into the lab (hint: it's the room that's the furthest WEST), as that's where the antidode is!  Good luck—you only have one small bag and your wits to get you through this. Better be quick... the poison is already taking effect. You'll only have time to make 15 moves before you die... and a move is any time you either leave a room, attempt to leave a room (and hit a locked door), or affirmatively decide to stay in a room (because the action of deciding that you're not done in a room counts as a 'move'." << endl;
    
    cout << endl;
    
        
    Hero * player1;  //creates pointer to Hero (which is the player)
    player1 = new Hero;  //creates new Hero (player) object
    
    
    Play quest;  //new "game" object
    victory = quest.gameStart (player1);  //starts game, sends player1 through game.  gameStart is a bool that will kick back either true or false
    
    if (victory == true)  //if Victory == true
    {cout << "You win!" << endl;}  //player wins!
    
    else
    {
        cout << "Sorry, you ran out of moves without finding the antidote! You lose!" << endl;  //but if it's false, they lose
    }
    
    
    cout << endl;  //for aesthetics
    cout << endl;
    
    
    cout << "Would you like to play again?" << endl;  //asks if they want to loop again
    
    while (validate == true)  //validate should be true again, so while this is true....
    {
        
        cout << "Select (1) to play, or (2) to exit" << endl;  //user menu, again
        
        cin >> userPlay;  //user input
        
        if (userPlay == '1' or userPlay == '2')  //validation.  If valid...
        {validate = false;}  //end loop
        else
        {  //but if not...
            cout << endl;
            cout << "sorry, invalid input!" << endl;
            cout << endl;
            validate = true;  //loop again
            
        }
    }
    
    
    validate = true;  //resets it so that next time the loop will still run
    
    switch (userPlay)  //swtich menu
    
    {
        case '1':
        {Again = true;  //either keeps it true (will run again)
            break;
        }
            
        case '2':
        {
            Again = false;  //or switches it to false, which exits the game
            break;
        }
    }
    
        delete player1;
        
    }
    
    
    cout << "Thanks for playing!" << endl;  //thanks user for playing
            
            
    return 0;
}