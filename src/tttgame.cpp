#include "tttgame.h"
#include <stdexcept>

// Function: Constructor
// Purpose: Creates an "empty board" in currentState --
// A 3x3 grid of "empty" square states
// Input: None
// Returns: Nothing
TicTacToeGame::TicTacToeGame()
{
	//set all squares to empty
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            currentState.mBoard[i][j] = GameState::Empty;
        }
    }
}

// Function: getBoard
// Purpose: Getter for the currentState member variable
// Input: None
// Returns: A GameState
GameState TicTacToeGame::getBoard() const
{
	//getter for currentState member variable
	return currentState;
}


// Function: setSquareState
// Purpose: Sets the position (indicated by row and col) to
// the indicated SquareState
// Input: 2 integers representing the row/column to set
//        A square state to set the r/c to
// Returns: True to indicate the state was set successfully
bool TicTacToeGame::setSquareState(unsigned short row, unsigned short col, GameState::SquareState state)
{
    if(row < 3 && col < 3 && currentState.mBoard[row][col] == GameState::Empty)
    {
        currentState.mBoard[row][col] = state;
        return true;
    }
    else
    {
        return false;
    }
}

// Function: setSquareState
// Purpose: Sets the position (indicated by the square number) to
// the indicated SquareState
// Input: An integer indicating the square number (upper left is #1)
//        A square state to set square to
// Returns: True to indicate the state was set successfully
bool TicTacToeGame::setSquareState(unsigned short square, GameState::SquareState state)
{
	//if current SquareState has been set
    if(square == 1 && currentState.mBoard[0][0] == GameState::Empty)
    {
        currentState.mBoard[0][0] = state;
        return true;
    }
    else if(square == 2 && currentState.mBoard[0][1] == GameState::Empty)
    {
        currentState.mBoard[0][1] = state;
        return true;
    }
    else if(square == 3 && currentState.mBoard[0][2] == GameState::Empty)
    {
        currentState.mBoard[0][2] = state;
        return true;
    }
    else if(square == 4 && currentState.mBoard[1][0] == GameState::Empty)
    {
        currentState.mBoard[1][0] = state;
        return true;
    }
    else if(square == 5 && currentState.mBoard[1][1] == GameState::Empty)
    {
        currentState.mBoard[1][1] = state;
        return true;
    }
    else if(square == 6 && currentState.mBoard[1][2] == GameState::Empty)
    {
        currentState.mBoard[1][2] = state;
        return true;
    }
    else if(square == 7 && currentState.mBoard[2][0] == GameState::Empty)
    {
        currentState.mBoard[2][0] = state;
        return true;
    }
    else if(square == 8 && currentState.mBoard[2][1] == GameState::Empty)
    {
        currentState.mBoard[2][1] = state;
        return true;
    }
    else if(square == 9 && currentState.mBoard[2][2] == GameState::Empty)
    {
        currentState.mBoard[2][2] = state;
        return true;
    }
	return false;
}

// Function: getBoard
// Purpose: Determines if there's a winner and returns the symbol
// Input: None
// Returns: 'X' to indicate X wins
//            'O' to indicate O wins
//            'N' to indicate tie game
//            ' ' to indicate no winner yet
char TicTacToeGame::getWinner()
{
    //let's check wins based on each player
    
    for(int i = 0; i < 3; i++)
    {
        //check horizontals for X win
        if(currentState.mBoard[i][0] == GameState::X &&
           currentState.mBoard[i][1] == GameState::X &&
           currentState.mBoard[i][2] == GameState::X)
        {
            return 'X';
        }
        //check horizontals for O win
        if(currentState.mBoard[i][0] == GameState::O &&
           currentState.mBoard[i][1] == GameState::O &&
           currentState.mBoard[i][2] == GameState::O)
        {
            return 'O';
        }
        
        //check verticals for X win
        if(currentState.mBoard[0][i] == GameState::X &&
           currentState.mBoard[1][i] == GameState::X &&
           currentState.mBoard[2][i] == GameState::X)
        {
            return 'X';
        }
        //check verticals for O win
        if(currentState.mBoard[0][i] == GameState::O &&
           currentState.mBoard[1][i] == GameState::O &&
           currentState.mBoard[2][i] == GameState::O)
        {
            return 'O';
        }
    }

    //check diagonals for X win
    if (currentState.mBoard[0][0] == GameState::X &&
        currentState.mBoard[1][1] == GameState::X &&
        currentState.mBoard[2][2] == GameState::X)
    {
        return 'X';
    }
    else if (currentState.mBoard[0][2] == GameState::X &&
             currentState.mBoard[1][1] == GameState::X &&
             currentState.mBoard[2][0] == GameState::X)
    {
        return 'X';
    }
    //check diagonals for O win
    if (currentState.mBoard[0][0] == GameState::O &&
        currentState.mBoard[1][1] == GameState::O &&
        currentState.mBoard[2][2] == GameState::O)
    {
        return 'O';
    }
    else if (currentState.mBoard[0][2] == GameState::O &&
             currentState.mBoard[1][1] == GameState::O &&
             currentState.mBoard[2][0] == GameState::O)
    {
        return 'O';
    }
    
    //now check for a tie: no winners and no empty spaces left
    int count = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(currentState.mBoard[i][j] == GameState::Empty)
            {
                count++;
            }
        }
    }
    if(count == 0 && getWinner() != 'X' && getWinner() != 'O')
    {
        return 'N';
    }
    //otherwise return that the game is not over yet
	return ' ';
}
