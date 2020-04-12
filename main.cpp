#include "gwindow.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, const char* argv[])
{
	// Terminal for the "screen"
	GTerminal term(400, 400);
	term.showCursor(false);

	// TODO: Implement TicTacToe game
    //draw game board

    char state = '0'; // The game board's state
    //creating game board
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    
    std::stringstream ss;
    
    //set player to X first
    std::string player = "X";

    while (1)
    {
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
        }
        else if(player == "O")
        {
            term.appendText("O's move...");
            pause(1000);
            //ask AI what move it would like
        }
        
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

        switch (state)
        {
        case 1:
                if(board[0][0] != '1')
                {
                    throw std::invalid_argument("Please select a valid square!");
                }
                //put player's symbol in the first square
                if(player == "X")
                {
                    //put X in first square
                    board[0][0] = 'X';
                }
                if(player == "O")
                {
                    //put O in first square
                    board[0][0] = 'O';
                }
                break;
        case 2:
                //put player's symbol in the second square
                if(board[0][1] != '2')
                {
                    throw std::invalid_argument("Please select a valid square!");
                }
                if(player == "X")
                {
                    //put X in first square
                    board[0][1] = 'X';
                }
                if(player == "O")
                {
                    //put O in first square
                    board[0][1] = 'O';
                }
                break;
        case 3:
                //put player's symbol in the third square
                if(board[0][2] != '3')
                {
                    throw std::invalid_argument("Please select a valid square!");
                }
                if(player == "X")
                {
                    //put X in first square
                    board[0][2] = 'X';
                }
                if(player == "O")
                {
                    //put O in first square
                    board[0][2] = 'O';
                }
                break;
        case 4:
                //put player's symbol in the fourth square
                if(board[1][0] != '4')
                {
                    throw std::invalid_argument("Please select a valid square!");
                }
                if(player == "X")
                {
                    //put X in first square
                    board[1][0] = 'X';
                }
                if(player == "O")
                {
                    //put O in first square
                    board[1][0] = 'O';
                }
                break;
        case 5:
                //put player's symbol in the fifth square
                if(board[1][1] != '5')
                {
                    throw std::invalid_argument("Please select a valid square!");
                }
                if(player == "X")
                {
                    //put X in first square
                    board[1][1] = 'X';
                }
                if(player == "O")
                {
                    //put O in first square
                    board[1][1] = 'O';
                }
                break;
        case 6:
                //put player's symbol in the sixth square
                if(board[1][2] != '6')
                {
                    throw std::invalid_argument("Please select a valid square!");
                }
                if(player == "X")
                {
                    //put X in first square
                    board[1][2] = 'X';
                }
                if(player == "O")
                {
                    //put O in first square
                    board[1][2] = 'O';
                }
                break;
        case 7:
                //put player's symbol in the seventh square
                if(board[2][0] != '7')
                {
                    throw std::invalid_argument("Please select a valid square!");
                }
                if(player == "X")
                {
                    //put X in first square
                    board[2][0] = 'X';
                }
                if(player == "O")
                {
                    //put O in first square
                    board[2][0] = 'O';
                }
                break;
        case 8:
                //put player's symbol in the eighth square
                if(board[2][1] != '8')
                {
                    throw std::invalid_argument("Please select a valid square!");
                }
                if(player == "X")
                {
                    //put X in first square
                    board[2][1] = 'X';
                }
                if(player == "O")
                {
                    //put O in first square
                    board[2][1] = 'O';
                }
                break;
        case 9:
                //put player's symbol in the ninth square
                if(board[2][2] != '9')
                {
                    throw std::invalid_argument("Please select a valid square!");
                }
                if(player == "X")
                {
                    //put X in first square
                    board[2][2] = 'X';
                }
                if(player == "O")
                {
                    //put O in first square
                    board[2][2] = 'O';
                }
                break;
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
