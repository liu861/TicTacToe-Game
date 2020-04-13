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
	SECTION("Test constructor for tttgame.cpp")
	{
        TicTacToeGame game;
        TicTacToeGame();
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                REQUIRE(game.setSquareState(i, j, GameState::Empty) == true);
            }
        }
	}
}


