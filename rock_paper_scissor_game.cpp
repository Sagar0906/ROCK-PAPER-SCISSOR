#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#include <string>


enum Selection {
    NONE,
    ROCK,
    PAPER,
    SCISSORS
};

enum Result {
    DRAW,
    WON,
    LOST,
    ERROR
};

// Figure out what the selection is from the specified integer
Selection GetSelectionForInteger(int inputInteger) {
    // TODO: Implement
    if(inputInteger==1)                   //This method tells the program the choice of the input by the user
        return Selection::ROCK;           //depending on the number the user has provided. EX 1=>ROCK and
    else if(inputInteger==2)              //2=>PAPER
        return Selection::PAPER;
    else if(inputInteger==3)
        return Selection::SCISSORS;
    else
        return Selection::NONE;           //If he user provides any other number than 1,2,3 then it is treated
}                                         //invalid input and NONE is returned



// Returns the selection for the AI according to a certain strategy
Selection GetAISelection(int rn, int pn, int sn) {
    if (rn>=pn && rn>=sn)
       return PAPER;                      //please refer the additional documnet attached with the code.It explains
    if (pn>=rn && pn>=sn)                 //the logic using probabilistic model.
       return SCISSORS;
    if (sn>=pn && sn>=rn)
       return ROCK;                      //Although the code shows warning thet control reaches end of non-void    
}                                        //function. This warning shows if there is nothing to return. But i have
                                         //taken care that there is always something to return.
// Compares the user's selection to the AI's selection,
// and determines the result of the round. If the user beats
// the AI it is considered a WIN, etc.
Result GetResult(Selection userSelection, Selection aiSelection) {
    if(userSelection==NONE)
    {                                                     //If the user selects invalid input then the GetResult functions returns ERROR
        return ERROR;                                     
    }                                                     
    if(userSelection==ROCK && aiSelection==PAPER)         //These are the only valid choices when the user will lose if it is guranteed 
    {                                                     //that there is a winner. In other words when the user has chosed a valid choice
    return LOST;                                          //and there is no draw.
    }
    if(userSelection==PAPER && aiSelection==SCISSORS)     
    {
    return LOST;
    }
    if(userSelection==SCISSORS && aiSelection==ROCK)
    {
    return LOST;
    }
    if(userSelection==aiSelection)
    {
    return DRAW;                                          //The output will be draw when both the user and AI end up choosing same choice.
    }
    else
        {
        return WON;                                       //In all other cases, the user is guranteed to win.
    }
    
       
}

// Display the instructions of what number corresponds to which selection
void ShowInitalUI(int roundNumb) {                                                             //This function shows the basic messages in the console to
    cout << "\nRound #" << roundNumb << ":\n";                                                 //guide the user through the game.
    cout << "\nEnter the number associated with the option below to select your move:";
    cout << "\n1. Rock";
    cout << "\n2. Paper";
    cout << "\n3. Scissors";
    cout << "\n> ";
}

// Displays the appropriate string for each Selection
void DisplaySelection(Selection a_nSelection) {
    // TODO: Implement
    if(a_nSelection==ROCK)                                //this method shows what the user has chosen in the output screen.
    cout<<"ROCK";                                         //If the user chooses something else then INVALID SELECTION is shown.
    if(a_nSelection==PAPER)
        cout<<"PAPER";
    if(a_nSelection==SCISSORS)
        cout<<"SCISSORS";
    if(a_nSelection==NONE)
        cout<<"INVALID SELECTION";
}

// Displays an appropriate string for each Result
void DisplayResult(Result result) {
    if(result == WON) {
        cout<<"\n\n YOU have WON this round";             //The Getresult function evaluates the user and AI chices and determines
                                                          // who is the winner. The DisplayResult function just displays the result
    } else if(result == LOST) {
        cout<<"\n\n The COMPUTER has WON this round";

    } else if(result == DRAW) {
        cout<<"\n\n This round is a DRAW";

    } else {
        cout<<"\n\n Oops! Something has gone wrong!";
    }
}
int play(int roundNumber,int rocknum, int papernum, int scissorsnum){
    int playoncemore;// Init variables
    
                                                                          // The play method is the crux of code. It is this method that alls all 
    Selection playerSelection = NONE;                                     //the required functions and displays the result.
    Selection aiSelection     = NONE;
                                                                          //The first parameter"roundnumber" is used to display which round is going on.
    // Start game                                                         //The other 3 parameters are used in implementing the AI which is explained in
                                                                          //attached document
    cout << "\nWelcome to a game of Rock, Paper, Scissors!\n";

    ShowInitalUI(roundNumber);

    // Gets player input
    int input;
    if(input==1)
      rocknum++;                                                          //Implementation of AI
    if(input==2)
      papernum++;
    if(input==3)
      scissorsnum++;
    cin>>input;
    
   

    // TODO: Use input apporpriately
    // Hint: Look up the 'atoi' function to parse the string to int
    int playerInputInt;
    
    playerInputInt=input;   
    playerSelection = GetSelectionForInteger(playerInputInt);

    // Show selected option
    cout<<"\nYou have Selected: ";
    DisplaySelection(playerSelection);

    // Let the AI make a selection
    aiSelection = GetAISelection(rocknum,papernum,scissorsnum);

    // Show option selected by AI
    cout<<"\nThe Computer has Selected: ";
    DisplaySelection(aiSelection);

    // Display final result
    Result result = GetResult(playerSelection, aiSelection);
    DisplayResult(result);
   
    cout<<endl;
    cout<<"Do you want to play the game again"<<endl<<"1.yes"<<endl;
    cout<<"enter anything else if you want to quit playing"<<endl;
    cin>>playoncemore;
    return playoncemore;                              //Player can continue the game only if he enters 1. That 1 is returned by the play function.
    }                                                 //Basically it returns anything that the player inputs after the question prompts.             

int main(int argc, const char * argv[]) {
    int roundNum=1;
    int r=0;
    int p=0;
    int s=0;
   int k= play(roundNum,r,p,s);                             
    
    while(k==1)                                       //Now we know that player can continue the game only if he enters 1.So k acts as a global flag.
    { roundNum++;                                     //User can continue playing the game as long as k is 1. The game exits as soon as k!=1.
    
      k=play(roundNum,r,p,s);
    }
        

    cout<<"\n";

    cout << "\nThank you for playing!";

    return 0;                                        //the return type of main function is int so we need to return an integer.
}