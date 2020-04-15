#include "catch.hpp"
#include "tttgame.h"
#include "tttgameai.h"
#include "tttgamedata.h"

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

// Your tests -- only add sections
TEST_CASE("Student tests", "[student]") 
{
    // TODO: Add tests here!
	SECTION("Tests for tttgame.cpp")
	{
        TicTacToeGame game;
        //test constructor (and getBoard I guess)
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                REQUIRE(game.getBoard().mBoard[i][j] == GameState::Empty);
            }
        }
        //test setSquareState (by row and col)
        REQUIRE(game.setSquareState(0, 1, GameState::X) == true);
        //test setSquareState (by square)
        REQUIRE(game.setSquareState(9, GameState::X) == true);
        REQUIRE(game.setSquareState(9, GameState::O) == false);
        //test getWinner() game not finished
        REQUIRE(game.getWinner() == ' ');
        //test getWinner() for diagonals
        TicTacToeGame testXD;
        //diagonal from top left corner down
        testXD.setSquareState(0, 0, GameState::X);
        testXD.setSquareState(1, 1, GameState::X);
        testXD.setSquareState(2, 2, GameState::X);
        REQUIRE(testXD.getWinner() == 'X');
        //diagonal from top right corner down
        testXD.setSquareState(0, 0, GameState::Empty);
        testXD.setSquareState(0, 2, GameState::X);
        testXD.setSquareState(2, 0, GameState::X);
        REQUIRE(testXD.getWinner() == 'X');
        //test getWinner for rows
        TicTacToeGame testRows;
        //row 1
        testRows.setSquareState(0, 0, GameState::O);
        testRows.setSquareState(0, 1, GameState::O);
        testRows.setSquareState(0, 2, GameState::O);
        REQUIRE(testRows.getWinner() == 'O');
        //row 2
        testRows.setSquareState(0, 0, GameState::Empty);
        testRows.setSquareState(1, 0, GameState::O);
        testRows.setSquareState(1, 1, GameState::O);
        testRows.setSquareState(1, 2, GameState::O);
        REQUIRE(testRows.getWinner() == 'O');
        //row 3
        testRows.setSquareState(1, 0, GameState::Empty);
        testRows.setSquareState(1, 2, GameState::Empty);
        testRows.setSquareState(2, 0, GameState::O);
        testRows.setSquareState(2, 1, GameState::O);
        testRows.setSquareState(2, 2, GameState::O);
        REQUIRE(testRows.getWinner() == 'O');
        //test getWinner for columns
        TicTacToeGame testCols;
        //column 1
        testCols.setSquareState(1, GameState::X);
        testCols.setSquareState(4, GameState::X);
        testCols.setSquareState(7, GameState::X);
        REQUIRE(testCols.getWinner() == 'X');
        //column 2
        testCols.setSquareState(1, GameState::Empty);
        testCols.setSquareState(2, GameState::X);
        testCols.setSquareState(5, GameState::X);
        testCols.setSquareState(8, GameState::X);
        //column 3
        testCols.setSquareState(4, GameState::Empty);
        testCols.setSquareState(7, GameState::Empty);
        testCols.setSquareState(3, GameState::X);
        testCols.setSquareState(6, GameState::X);
        testCols.setSquareState(9, GameState::X);
        REQUIRE(testCols.getWinner() == 'X');
        //test for getWinner() tie
        TicTacToeGame tie;
        tie.setSquareState(1, GameState::X);
        tie.setSquareState(2, GameState::O);
        tie.setSquareState(3, GameState::O);
        tie.setSquareState(4, GameState::O);
        tie.setSquareState(5, GameState::X);
        tie.setSquareState(6, GameState::X);
        tie.setSquareState(7, GameState::X);
        tie.setSquareState(8, GameState::X);
        tie.setSquareState(9, GameState::O);
        REQUIRE(tie.getWinner() == 'N');
	}
    SECTION("Tests for tttgameai.cpp")
    {
        //create a new root gamestate
        GTNode* root = new GTNode;
        //create empty board
        for(int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                root->mState.mBoard[i][j] = GameState::Empty;
            }
        }
        //it's X's turn!
        bool xPlayer = true;
        GenStates(root, xPlayer);
        REQUIRE(root->mChildren[0]->mState.mBoard[0][0] == GameState::X);
        REQUIRE(root->mChildren[1]->mState.mBoard[0][1] == GameState::X);
        REQUIRE(root->mChildren[2]->mState.mBoard[0][2] == GameState::X);
        //etc etc???
        //test GetScore() function from manual board
        GTNode* testScore = new GTNode;
        testScore->mState.mBoard[0][0] = GameState::O;
        testScore->mState.mBoard[0][1] = GameState::X;
        testScore->mState.mBoard[0][2] = GameState::X;
        testScore->mState.mBoard[1][0] = GameState::X;
        testScore->mState.mBoard[1][1] = GameState::O;
        testScore->mState.mBoard[1][2] = GameState::O;
        testScore->mState.mBoard[2][0] = GameState::X;
        testScore->mState.mBoard[2][1] = GameState::O;
        testScore->mState.mBoard[2][2] = GameState::X;
        //test for tie
        REQUIRE(GetScore(testScore->mState) == 0);
        testScore->mState.mBoard[2][1] = GameState::Empty;
        testScore->mState.mBoard[2][2] = GameState::O;
        //test for O win
        REQUIRE(GetScore(testScore->mState) == 1);
        testScore->mState.mBoard[2][1] = GameState::X;
        testScore->mState.mBoard[2][2] = GameState::X;
        //test for X win
        REQUIRE(GetScore(testScore->mState) == -1);
        //test MinPlayer
        //empty board
        REQUIRE(MinPlayer(root) == 0.0);
        //test MaxPlayer
        //empty board
        REQUIRE(MaxPlayer(root) == 0.0);
        //test MinimaxDecide
        //???
        //test pickMove
        //given a winning move for X next, O should prevent it
        /*TicTacToeGame game;
        game.setSquareState(2, GameState::O);
        game.setSquareState(5, GameState::X);
        game.setSquareState(9, GameState::X);
        REQUIRE(pickMove(game.getBoard()) == 1);
        //given a winning move for O next, O should choose it
        game.setSquareState(1, GameState::O);
        game.setSquareState(7, GameState::X);
        REQUIRE(pickMove(game.getBoard()) == 3);*/
    }
}


