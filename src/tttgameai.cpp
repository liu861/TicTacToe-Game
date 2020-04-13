#include "tttgameai.h"

// Function: GenStates
// Purpose: Generates the game tree starting at the inputted root
// Input: A GTNode pointer with the 1st state completed
//        A boolean to indicate who's turn it is (true means it's X's turn)
// Returns: Nothing
void GenStates(GTNode* root, bool xPlayer)
{
	//iterate through all squares of root game state
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            //if a space is empty, generate a child node
            if(root->mState.mBoard[i][j] == GameState::Empty)
            {
                //create new child node
                GTNode* child = new GTNode;
                
                //set child's board to root's board
                child->mState.mBoard[i][j] = root->mState.mBoard[i][j];
                
                //set empty position to player's symbol
                if(xPlayer)
                {
                    child->mState.mBoard[i][j] = GameState::X;
                }
                else
                {
                    child->mState.mBoard[i][j] = GameState::O;
                }
                
                //add child to vector of children
                root->mChildren.push_back(child);
                
                //generate more child nodes for the child, using recursion
                if(child->mState.mBoard[i][j] == GameState::Empty)
                {
                    if(xPlayer)
                    {
                        GenStates(child, false);
                    }
                    else
                    {
                        GenStates(child, true);
                    }
                }
            }
        }
    }
}

// Function: GetScore
// Purpose: Examines the inputted game board to determine a winner
// Input: A game state representing a game board
// Returns: Everything is relative to O, so...
//        1.0 to indicate O wins on this board
//        0.0 to indicate tie game
//        -1.0 to indicate X wins on this board
float GetScore(const GameState& state)
{
	// TODO: IMPLEMENT
	return 0.0; // FIX RETURN VALUE
}

// Function: MinPlayer
// Purpose: Determines the minimum score this branch (or leaf) can yield
// Input: A GameTree node
// Returns: The game score meaning...
//        1.0 to indicate O wins on this board
//        0.0 to indicate tie game
//        -1.0 to indicate X wins on this board
float MinPlayer(const GTNode* node)
{
	// TODO: IMPLEMENT
	return 0.0; // FIX RETURN VALUE
}

// Function: MaxPlayer
// Purpose: Determines the maximum score this branch (or leaf) can yield
// Input: A GameTree node
// Returns: The game score meaning...
//        1.0 to indicate O wins on this board
//        0.0 to indicate tie game
//        -1.0 to indicate X wins on this board
float MaxPlayer(const GTNode* node)
{
	// TODO: IMPLEMENT
	return 0.0; // FIX RETURN VALUE
}

// Function: MinimaxDecide
// Purpose: Determines which subtree leads to O winning
// Input: A GameTree node
// Returns: The GTNode* with the winning game state
const GTNode* MinimaxDecide(const GTNode* root)
{
	// TODO: IMPLEMENT
	return nullptr; // FIX RETURN VALUE
}

// Function: pickMove
// Purpose: Decides which square the AI should select
// Input: A game state with the current board's state
// Returns: The square number (1 through 9) the AI selects
unsigned pickMove(const GameState& board)
{
	// TODO: IMPLEMENT
	return 0; // FIX RETURN VALUE
}
