#include "gwindow.h"
#include "tttgame.h"
#include "tttgameai.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, const char* argv[])
{
	// Terminal for the "screen"
	GTerminal term(400, 400);
	term.showCursor(false);

    char state = '0'; // The game board's state
    //creating game board
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    TicTacToeGame game;
    std::stringstream ss;
    
    //set player to X first
    std::string player = "X";

    while (game.getWinner() == ' ')
    {
        //draw game board
        term.clear();
        ss << "\n\n\n\n";
        ss << "\t    " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
        ss << "\t   -----------\n";
        ss << "\t    " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
        ss << "\t   -----------\n";
        ss << "\t    " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
        ss << "\n\n\n\n";
        
        ss<< "___________________________________\n";
        
        term.appendText(ss.str());
        pause(1000);
        
        if(player == "X")
        {
            term.appendText("X's move...");
            pause(1000);
            while (term.hasEvents())
            {
                GEvent e = term.getEvent();
                if (e.Type == EventType::KeyDown)
                {
                    int key = e.Event.Key.Code;
                    if (key == 1 || key == 2 || key == 3 ||
                        key == 4 || key == 5 || key == 6 ||
                        key == 7 || key == 8 || key == 9)
                    {
                        state = key;
                        ss << key;
                        term.appendText(ss.str());
                    }
                    else if (key == 0)
                    {
                        return 0;
                    }
                }
            }
            switch(state)
            {
            case 1:
                    //put player's symbol in the first square
                    if(board[0][0] != '1')
                    {
                        break;
                    }
                    if(player == "X")
                    {
                        //put X in first square
                        board[0][0] = 'X';
                        game.setSquareState(1, GameState::X);
                    }
                    break;
            case 2:
                    if(board[0][1] != '2')
                    {
                        break;
                    }
                    //put player's symbol in the second square
                    if(player == "X")
                    {
                        //put X in second square
                        board[0][1] = 'X';
                        game.setSquareState(2, GameState::X);
                    }
                    break;
            case 3:
                    if(board[0][2] != '3')
                    {
                        break;
                    }
                    //put player's symbol in the third square
                    if(player == "X")
                    {
                        //put X in third square
                        board[0][2] = 'X';
                        game.setSquareState(3, GameState::X);
                    }
                    break;
            case 4:
                    if(board[1][0] != '4')
                    {
                        break;
                    }
                    //put player's symbol in the fourth square
                    if(player == "X")
                    {
                        //put X in fourth square
                        board[1][0] = 'X';
                        game.setSquareState(4, GameState::X);
                    }
                    break;
            case 5:
                    if(board[1][1] != '5')
                    {
                        break;
                    }
                    //put player's symbol in the fifth square
                    if(player == "X")
                    {
                        //put X in fifth square
                        board[1][1] = 'X';
                        game.setSquareState(5, GameState::X);
                    }
                    break;
            case 6:
                    //put player's symbol in the sixth square
                    if(board[1][2] != '6')
                    {
                        break;
                    }
                    if(player == "X")
                    {
                        //put X in sixth square
                        board[1][2] = 'X';
                        game.setSquareState(6, GameState::X);
                    }
                    break;
            case 7:
                    //put player's symbol in the seventh square
                    if(board[2][0] != '7')
                    {
                        break;
                    }
                    if(player == "X")
                    {
                        //put X in seventh square
                        board[2][0] = 'X';
                        game.setSquareState(7, GameState::X);
                    }
                    break;
            case 8:
                    //put player's symbol in the eighth square
                    if(board[2][1] != '8')
                    {
                        break;
                    }
                    if(player == "X")
                    {
                        //put X in eighth square
                        board[2][1] = 'X';
                        game.setSquareState(8, GameState::X);
                    }
                    break;
            case 9:
                    //put player's symbol in the ninth square
                    if(board[2][2] != '9')
                    {
                        break;
                    }
                    if(player == "X")
                    {
                        //put X in ninth square
                        board[2][2] = 'X';
                        game.setSquareState(9, GameState::X);
                    }
                    break;
            }
        }
        else if(player == "O")
        {
            term.appendText("O's move...");
            pause(1000);
            int move = pickMove(game.getBoard());
            game.setSquareState(move, GameState::O);
        }
        //switch players
        if(player == "X")
        {
            player = "O";
        }
        else if(player == "O")
        {
            player = "X";
        }
    }
    if(game.getWinner() == 'N')
    {
        term.appendText("!!!!!!!!!!!! TIE GAME !!!!!!!!!!!!");
    }
    if(game.getWinner() == 'O')
    {
        term.appendText("!!!!!!!!!!!!! O WINS !!!!!!!!!!!!!");
    }
    if(game.getWinner() == 'X')
    {
        term.appendText("!!!!!!!!!!!!! X WINS !!!!!!!!!!!!!");
    }
	return 0;
}
