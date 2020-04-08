#include "tttgame.h"

TicTacToeGame::TicTacToeGame()
{
	// TODO: IMPLEMENT
}

GameState TicTacToeGame::getBoard() const
{
	// TODO: IMPLEMENT
	return *(new GameState); // FIX RETURN VALUE
}


bool TicTacToeGame::setSquareState(unsigned short row, unsigned short col, GameState::SquareState state)
{
	// TODO: IMPLEMENT
	return false; // FIX RETURN VALUE
}

bool TicTacToeGame::setSquareState(unsigned short square, GameState::SquareState state)
{
	// TODO: IMPLEMENT
	return false; // FIX RETURN VALUE
}

char TicTacToeGame::getWinner()
{
	// TODO: IMPLEMENT
	return ' '; // FIX RETURN VALUE
}
