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
    //creating game board for output in terminal
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    TicTacToeGame game;
    //create stringstream for appending text
    std::stringstream ss;
    
    //set player to X first
    std::string player = "X";

    while (1)
    {
        //draw game board
        term.clear();
        ss.str(std::string());
        ss << "\n\n\n\n";
        ss << "\t    " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
        ss << "\t   -----------\n";
        ss << "\t    " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
        ss << "\t   -----------\n";
        ss << "\t    " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
        ss << "\n\n\n\n";
        
        ss << "__________________________________\n";
        //check if game is over
        if(game.getWinner() == 'N')
        {
            ss << "!!!!!!!!!!!! TIE GAME !!!!!!!!!!!!";
            term.appendText(ss.str());
            pause(10000);
        }
        if(game.getWinner() == 'O')
        {
            ss << "!!!!!!!!!!!!! O WINS !!!!!!!!!!!!!";
            term.appendText(ss.str());
            pause(10000);
        }
        if(game.getWinner() == 'X')
        {
            ss << "!!!!!!!!!!!!! X WINS !!!!!!!!!!!!!";
            term.appendText(ss.str());
            pause(10000);
        }
        if(player == "X")
        {
            ss << "X's move...";
            term.appendText(ss.str());
            pause(10000);
            while (term.hasEvents())
            {
                GEvent e = term.getEvent();
                if (e.Type == EventType::KeyDown)
                {
                    int key = e.Event.Key.Code;
                    if (key == '1' || key == '2' || key == '3' ||
                        key == '4' || key == '5' || key == '6' ||
                        key == '7' || key == '8' || key == '9')
                    {
                        state = key;
                    }
                    else if (key == '0')
                    {
                        return 0;
                    }
                }
            }
            switch(state)
            {
            case '1':
                    if(board[0][0] != '1')
                    {
                        break;
                    }
                    //put X in first square
                    board[0][0] = 'X';
                    game.setSquareState(1, GameState::X);
                    term.appendText("1");
                    break;
            case '2':
                    if(board[0][1] != '2')
                    {
                        break;
                    }
                    //put X in second square
                    board[0][1] = 'X';
                    game.setSquareState(2, GameState::X);
                    term.appendText("2");
                    break;
            case '3':
                    if(board[0][2] != '3')
                    {
                        break;
                    }
                  
                    //put X in third square
                    board[0][2] = 'X';
                    game.setSquareState(3, GameState::X);
                    term.appendText("3");
                    break;
            case '4':
                    if(board[1][0] != '4')
                    {
                        break;
                    }
                    //put X in fourth square
                    board[1][0] = 'X';
                    game.setSquareState(4, GameState::X);
                    term.appendText("4");
                    break;
            case '5':
                    if(board[1][1] != '5')
                    {
                        break;
                    }
                    //put X in fifth square
                    board[1][1] = 'X';
                    game.setSquareState(5, GameState::X);
                    term.appendText("5");
                    break;
            case '6':
                    //put player's symbol in the sixth square
                    if(board[1][2] != '6')
                    {
                        break;
                    }
                    //put X in sixth square
                    board[1][2] = 'X';
                    game.setSquareState(6, GameState::X);
                    term.appendText("6");
                    break;
            case '7':
                    //put player's symbol in the seventh square
                    if(board[2][0] != '7')
                    {
                        break;
                    }
                    //put X in seventh square
                    board[2][0] = 'X';
                    game.setSquareState(7, GameState::X);
                    term.appendText("7");
                    break;
            case '8':
                    //put player's symbol in the eighth square
                    if(board[2][1] != '8')
                    {
                        break;
                    }
                    //put X in eighth square
                    board[2][1] = 'X';
                    game.setSquareState(8, GameState::X);
                    term.appendText("8");
                    break;
            case '9':
                    //put player's symbol in the ninth square
                    if(board[2][2] != '9')
                    {
                        break;
                    }
                    //put X in ninth square
                    board[2][2] = 'X';
                    game.setSquareState(9, GameState::X);
                    term.appendText("9");
                    break;
            }
        }
        else if(player == "O")
        {
            ss << "O's move...";
            term.appendText(ss.str());
            pause(10000);
            int move = pickMove(game.getBoard());
            game.setSquareState(move, GameState::O);
            term.appendText(std::to_string(move));
            pause(10000);
            if(move == 1)
            {
                board[0][0] = 'O';
            }
            if(move == 2)
            {
                board[0][1] = 'O';
            }
            if(move == 3)
            {
                board[0][2] = 'O';
            }
            if(move == 4)
            {
                board[1][0] = 'O';
            }
            if(move == 5)
            {
                board[1][1] = 'O';
            }
            if(move == 6)
            {
                board[1][2] = 'O';
            }
            if(move == 7)
            {
                board[2][0] = 'O';
            }
            if(move == 8)
            {
                board[2][1] = 'O';
            }
            if(move == 9)
            {
                board[2][2] = 'O';
            }
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
	return 0;
}
