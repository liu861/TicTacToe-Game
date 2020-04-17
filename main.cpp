#include "gwindow.h"
#include "tttgame.h"
#include "tttgameai.h"
#include <iostream>
#include <string>

int main(int argc, const char* argv[])
{
	// Terminal for the "screen"
	GTerminal term(400, 400);
	term.showCursor(false);

    char state = '0'; // The game board's state
    //create TicTacToe game
    TicTacToeGame game;
    
    //set player to X first
    std::string player = "X";
    //create board string for output
    std::string board;

    while (1)
    {
        term.clear();
        //clear board
        board.clear();
        //draw game board
        board += "\n\n\n\n";
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i == 0 && j == 0)
                {
                    board += "\t    ";
                }
                if(i == 1 && j == 0)
                {
                    board += "\t    ";
                }
                if(i == 2 && j == 0)
                {
                    board += "\t    ";
                }
                if(game.getBoard().mBoard[i][j] == GameState::Empty)
                {
                    if(i == 0 && j == 0)
                    {
                        board += "1";
                    }
                    if(i == 0 && j == 1)
                    {
                        board += "2";
                    }
                    if(i == 0 && j == 2)
                    {
                        board += "3";
                    }
                    if(i == 1 && j == 0)
                    {
                        board += "4";
                    }
                    if(i == 1 && j == 1)
                    {
                        board += "5";
                    }
                    if(i == 1 && j == 2)
                    {
                        board += "6";
                    }
                    if(i == 2 && j == 0)
                    {
                        board += "7";
                    }
                    if(i == 2 && j == 1)
                    {
                        board += "8";
                    }
                    if(i == 2 && j == 2)
                    {
                        board += "9";
                    }
                }
                else if(game.getBoard().mBoard[i][j] == GameState::X)
                {
                    board += "X";
                }
                else if(game.getBoard().mBoard[i][j] == GameState::O)
                {
                    board += "O";
                }
                if(j < 2)
                {
                    board += " | ";
                }
                if(j == 2)
                {
                    board += "\n";
                    if(i < 2)
                    {
                        board += "\t   -----------\n";
                    }
                }
                    
            }
        }
        board += "\n\n\n\n";
        board += "__________________________________\n";
        
        //check if game is over
        if(game.getWinner() == 'N')
        {
            board += "!!!!!!!!!!!! TIE GAME !!!!!!!!!!!!";
            term.appendText(board);
            pause(5000);
            return 0;
        }
        if(game.getWinner() == 'O')
        {
            board += "!!!!!!!!!!!!! O WINS !!!!!!!!!!!!!";
            term.appendText(board);
            pause(5000);
            return 0;
        }
        if(game.getWinner() == 'X')
        {
            board += "!!!!!!!!!!!!! X WINS !!!!!!!!!!!!!";
            term.appendText(board);
            pause(5000);
            return 0;
        }
        if(player == "X")
        {
            board += "X's move...";
            term.appendText(board);
            pause(10000);
            while(term.hasEvents())
            {
                GEvent e = term.getEvent();
                if(e.Type == EventType::KeyDown)
                {
                    int key = e.Event.Key.Code;
                    if(key == '1' || key == '2' || key == '3' ||
                       key == '4' || key == '5' || key == '6' ||
                       key == '7' || key == '8' || key == '9')
                    {
                        state = key;
                    }
                    else if(key == '0')
                    {
                        return 0;
                    }
                }
            }
            switch(state)
            {
            case '1':
                    game.setSquareState(1, GameState::X);
                    term.appendText("1");
                    break;
            case '2':
                    game.setSquareState(2, GameState::X);
                    term.appendText("2");
                    break;
            case '3':
                    game.setSquareState(3, GameState::X);
                    term.appendText("3");
                    break;
            case '4':
                    game.setSquareState(4, GameState::X);
                    term.appendText("4");
                    break;
            case '5':
                    game.setSquareState(5, GameState::X);
                    term.appendText("5");
                    break;
            case '6':
                    game.setSquareState(6, GameState::X);
                    term.appendText("6");
                    break;
            case '7':
                    game.setSquareState(7, GameState::X);
                    term.appendText("7");
                    break;
            case '8':
                    game.setSquareState(8, GameState::X);
                    term.appendText("8");
                    break;
            case '9':
                    game.setSquareState(9, GameState::X);
                    term.appendText("9");
                    break;
            }
        }
        else if(player == "O")
        {
            board += "O's move...";
            term.appendText(board);
            //pause(10000);
            int move = pickMove(game.getBoard());
            game.setSquareState(move, GameState::O);
            term.appendText(std::to_string(move));
            pause(5000);
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
