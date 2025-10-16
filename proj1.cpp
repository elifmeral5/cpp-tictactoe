T/*
  File: proj1.cpp
  Project: CMSC 202 Project 1, Spring 2025
  Author: Elif Meral
  Date: 02/25/25
  Section: 10/14
  E-mail: elifm1@umbc.edu

  This file contains the main driver program for Projecct 1.
  This file creates a Tic-Tac-Toe game where the user decides which letter to be
  and plays as many games as they like.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const string SYMBOL_1 = "X";  // symbol for player X
const string SYMBOL_2 = "O";  // symbol for player O
const int BOARD_SIZE = 3;     // board size for tic-tac-toe

// Name: mainMenu
// PreCondition: none
// PostCondition: returns true or false depending on user wanting to continue game or not
bool mainMenu();


// Name: chooseSymbol                                                                       
// PreCondition: given symbol1 and symbol2
// PostCondition: returns chosen symbol by the user
string chooseSymbol(string SYMBOL1, string SYMBOL2);

// Name: displayBoard                                                                                                                                                          
// PreCondition: given board and board size                                                                                                                                             
// PostCondition: ooutputs board onto console
void displayBoard(string board[BOARD_SIZE][BOARD_SIZE], int BOARD_SIZE);

// Name: checkMove                                                                                                                                                               
// PreCondition: given board, row number and column number                                                                                                                                        
// PostCondition: returns true or false 
  bool checkMove(string board[BOARD_SIZE][BOARD_SIZE], int row, int column);

// Name: checkWin                                                                                                                                                                                      
// PreCondition: given board, player and counter                                                                                                                                                       
// PostCondition: returns true or false
bool checkWin(string board, string player, int count);

// Name: playGame                                                                                                                                                                    
// PreCondition: none                                                                                                                                                                                
// PostCondition: plays gaame
void playGame();

// MAIN 
int main(){
  
  while (mainMenu()){
    playGame();
  }
  return 0;
}

// FUNCTIONS

// Description: Asks the user if they want to play the game or quit and continues acccordingly
bool mainMenu(){
  
  int choice = 0;     // users choice
  bool check = false; // checks user input validity

  //Ask user decision
  cout << "What would you like to do?" << endl;
  cout<< "1. Play New Game" << endl;
  cout << "2. Quit" << endl;
  cin >> choice;

  // goes through loop while user input is not valid 
  while (check == false){
    
    // goes through switch on users decision
    switch(choice){
      
    case 1:
      check = true;
      return true;
      
    case 2:
      check = true;
      cout << "Thank you for playing Tic-Tac Toe" << endl;
      return false;
      
    default:
      cout << "What would you like to do?" << endl;
      cout<< "1. Play New Game" << endl;
      cout << "2. Quit" << endl;
      cin >> choice;
      check = false;
      break;
    }
   
  }
  return false;
}

// Description: Asks the first player to choose one of the correct symbols 
string chooseSymbol(string symbol1, string symbol2){
  string pick = " "; // Users symbol  pick
  
  cout << "What symbol would you like to be? (" << symbol1 << " or " << symbol2 << ")" << endl;
  cin >> pick;

  // checks to make sure user has chosen correct symbol, if not user will be asked again
  while (pick != symbol1 && pick != symbol2){
    cout << "What symbol would you like to be? (" << symbol1 << " or " << symbol2 << ")" << endl;
    cin >> pick;
  }
  return pick;
 }

// Description: Displays the current board being played
void displayBoard(string board[BOARD_SIZE][BOARD_SIZE], int BOARD_SIZE){
  ofstream myfile ("proj1_data.txt");
  cout << "Current board: " << endl;
  
  // iterates through the 2D array that contains the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    
        for (int j = 0; j < BOARD_SIZE; j++) {
	  
	  // if the array index contains nothing, the code prints it with a _
	  if (board[i][j] == " "){
	    cout << "_ ";
	    myfile << "_ ";
	  }
	  // array is printed with the symbol containing it
	  else{
	    cout << board[i][j] << " "; 
	    myfile << board[i][j] << " ";
	  }

	}
	cout << endl;
	myfile << endl;
  }
  
}

// Description: Checks the users choice of where to place the symbol to make sure it is not already taken by another symbol that it is within bounds
bool checkMove(string board[BOARD_SIZE][BOARD_SIZE], int row, int column){
  // checks for not in bound choice or not empty index
  if (row < 0 || row > 2 || column < 0 || column > 2 || board[row][column] != "_"){
    cout << "Invalid move. Try again." << endl;
    displayBoard(board,BOARD_SIZE);
    return false;
   }
  else{
   return true;
  }


 }

//Description: Checks after each turn to see if the current player has won the game or if it is a draw
bool checkWin(string board[BOARD_SIZE][BOARD_SIZE], string player, int count){
  // Checks top row
   if (board[0][0] == player && board[0][1] == player && board[0][2] == player){
     cout << "Player " << player << " wins!" << endl; 
     return true;
     
     // Checks middle row
   }else if (board[1][0] == player && board[1][1] == player && board[1][2] == player){
     cout << "Player " << player << " wins!" << endl;
     return true;
     
     // Checks bottom row
   }else if (board[2][0] == player && board[2][1] == player && board[2][2] == player){
     cout << "Player " << player << " wins!" << endl;
     return true;
     
     // Checks left column
   }else if(board[0][0] == player && board[1][0] == player && board[2][0] == player){
     cout << "Player " << player << " wins!" << endl;
     return true;
     
     // Checks middle column
   }else if (board[0][1] == player && board[1][1] == player && board[2][1] == player){
     cout << "Player " << player << " wins!" << endl;
     return true;
     
     // checks right column 
   }else if (board[0][2] == player && board[1][2] == player && board[2][2] == player){
     cout << "Player " << player << " wins!" << endl;
     return true;
     
     // checks diagonal to the right
   }else if (board[0][0] == player && board[1][1] == player && board[2][2] == player){
     cout << "Player " << player << " wins!" << endl;
     return true;
     
     // checks diagonal to the left
   }else if (board[0][2] == player && board[1][1] == player && board[2][0] == player){
     cout << "Player " << player << " wins!" << endl;
     return true;

     // checks to see if the board is full
   }else if(count == 9){
     cout << "The game is a draw!" << endl;
     return true;

     // when none is true from above, returns false to continue game
   }else{
     return false;
   }
  

 }

//Description: Allows the game to be played 
void playGame(){
  
  string board[BOARD_SIZE][BOARD_SIZE] = { // local variable for the 2D array which is the game board
      {"_", "_", "_"},
      {"_", "_", "_"},
      {"_", "_", "_"}
    };  
  string player1 = " "; // player1 set to an empty string since symbol is not yet chosen
  string player2 = " "; // player2 set to an empty string since symbol is not yet chosen

  // sets the symbols for both of the players
  player1 = chooseSymbol(SYMBOL_1, SYMBOL_2);
  // player2 symbol is set depending on player1's choice
  if (player1 == SYMBOL_1){
    player2 = SYMBOL_2;
  }
  else{
    player2 = SYMBOL_1;
  }
   
  displayBoard(board, BOARD_SIZE);
  
  string turn = player1; // curent players turn
  int row = 0;           // starting row number
  int column = 0;        // starting column number
  int count = 0;         // counting amount of plays

  // Continues play as long as there is no winner or draw
  do{
    bool check = false;  // checks users row and column input

    // Continues to ask as long as user has no input or invalid input
    while (check == false){
      cout << "Player " << turn << ", enter row and column (0-2): " << endl;
      cin >> row;
      cin >> column;
      
      // Rechecks to see if the input is valid
      check = checkMove(board, row, column);

    }

    // Board is updated with the correct symbol on the board
    board[row][column] = turn;

    // Shows new board
    displayBoard(board, BOARD_SIZE);
    
    // Increases count as turn is taken
    count += 1;

    // If player wins or there is a draw, it ends game	
    if (checkWin(board, turn, count)){
      cout << "Thank you for playing Tic-Tac Toe" << endl;
      break;
    }

    // Changes turns from one player to the next
    if (turn == player1){
      turn = player2;
    }
    else{
      turn = player1;
    }
	
  }while(!checkWin(board, turn, count));
      
   
}
