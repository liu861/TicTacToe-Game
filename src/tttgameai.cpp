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
                    //if it was just X's turn, now it's O's turn
                    if(xPlayer)
                    {
                        GenStates(child, false);
                    }
                    //otherwise, it's X's turn again!
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
    for(int i = 0; i < 3; i++)
       {
           //check horizontals for X win
           if(state.mBoard[i][0] == GameState::X &&
              state.mBoard[i][1] == GameState::X &&
              state.mBoard[i][2] == GameState::X)
           {
               return -1.0;
           }
           //check horizontals for O win
           if(state.mBoard[i][0] == GameState::O &&
              state.mBoard[i][1] == GameState::O &&
              state.mBoard[i][2] == GameState::O)
           {
               return 1.0;
           }
           
           //check verticals for X win
           if(state.mBoard[0][i] == GameState::X &&
              state.mBoard[1][i] == GameState::X &&
              state.mBoard[2][i] == GameState::X)
           {
               return -1.0;
           }
           //check verticals for O win
           if(state.mBoard[0][i] == GameState::O &&
              state.mBoard[1][i] == GameState::O &&
              state.mBoard[2][i] == GameState::O)
           {
               return 1.0;
           }
       }

       //check diagonals for X win
       if (state.mBoard[0][0] == GameState::X &&
           state.mBoard[1][1] == GameState::X &&
           state.mBoard[2][2] == GameState::X)
       {
           return -1.0;
       }
       else if (state.mBoard[0][2] == GameState::X &&
                state.mBoard[1][1] == GameState::X &&
                state.mBoard[2][0] == GameState::X)
       {
           return -1.0;
       }
       //check diagonals for O win
       if (state.mBoard[0][0] == GameState::O &&
           state.mBoard[1][1] == GameState::O &&
           state.mBoard[2][2] == GameState::O)
       {
           return 1.0;
       }
       else if (state.mBoard[0][2] == GameState::O &&
                state.mBoard[1][1] == GameState::O &&
                state.mBoard[2][0] == GameState::O)
       {
           return 1.0;
       }
    //if no winners and no empty spaces left, then it's a tie
    return 0.0;
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
	//MinPlayer in this game is X, wants to minimize score!
    //if node is a leaf, return the score
    if(node->mChildren.empty())
    {
        return GetScore(node->mState);
    }
    //otherwise return the smallest maximum score of all child nodes
    //set minScore to infinity
    float minScore = std::numeric_limits<float>::infinity();
    //iterate through all child nodes/subtrees
    for(const GTNode* child : node->mChildren)
    {
        //look at worst move from opposing player (O)
        //find the minimum value given by MaxPlayer
        minScore = std::min(minScore, MaxPlayer(child));
    }
	return minScore;
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
	//MaxPlayer in this game is O, wants to maximize score!
    //if node is a leaf, return the score
    if(node->mChildren.empty())
    {
        return GetScore(node->mState);
    }
    //otherwise return the largest minimum score of all child nodes
    //set maxScore to negative infinity
    float maxScore = -std::numeric_limits<float>::infinity();
    //iterate through all child nodes/subtrees
    for(const GTNode* child : node->mChildren)
    {
        //look at worst move from opposing player (X)
        //find maximum value given by MinPlayer
        maxScore = std::max(maxScore, MinPlayer(child));
    }
	return maxScore;
}

// Function: MinimaxDecide
// Purpose: Determines which subtree leads to O winning
// Input: A GameTree node
// Returns: The GTNode* with the winning game state
const GTNode* MinimaxDecide(const GTNode* root)
{
	// TODO: IMPLEMENT
    //go through each subtree and find the maximum value as given by MinPlayer
    //because that gives the move that if worst for X, best for O
    //start with given node(root), which is current state of the game
    const GTNode* move = nullptr;
    float maxScore = -std::numeric_limits<float>::infinity();
    //go through each child node of the root
    for(const GTNode* child : root->mChildren)
    {
        //find the node with the largest MinPlayer score
        float largest = MinPlayer(child);
        //make the move to yield the state found above
        if(largest > maxScore)
        {
            maxScore = largest;
            //set move to the largest child
            move = child;
        }
    }
	return move;
}

// Function: pickMove
// Purpose: Decides which square the AI should select
// Input: A game state with the current board's state
// Returns: The square number (1 through 9) the AI selects
unsigned pickMove(const GameState& board)
{
    //determine the GameState that AI wants to select
    //create a root to set to current board's state
    GTNode* root = new GTNode;
    //set root's GameState to given state
    root->mState = board;
    //create new node that is the winning subtree
    const GTNode* winState = MinimaxDecide(root);
    int row = 0;
    int col = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            //if board differs in a square, then that is the move that O should make
            if(board.mBoard[i][j] != winState->mState.mBoard[i][j])
            {
                row = i;
                col = j;
            }
        }
    }
    //return the square number that the AI should select
    if(row == 0 && col == 0)
    {
        return 1;
    }
    if(row == 0 && col == 1)
    {
        return 2;
    }
    if(row == 0 && col == 2)
    {
        return 3;
    }
    if(row == 1 && col == 0)
    {
        return 4;
    }
    if(row == 1 && col == 1)
    {
        return 5;
    }
    if(row == 1 && col == 2)
    {
        return 6;
    }
    if(row == 2 && col == 0)
    {
        return 7;
    }
    if(row == 2 && col == 1)
    {
        return 8;
    }
    return 9;
}
