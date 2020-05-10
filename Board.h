//
// Created by iliyan on 10.05.20 г..
//

#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

//constants for player positions
const char EMPTY_SPACE = '*';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

class Board {

public:

    //board itself
    char board[3][3];

    //generic constructor
    Board();

    //coping constructor
    Board(char board1[3][3]);

    //function for showing board
    void ShowBoard();

    //checks if somebody won, returns winner's symbol
    char FoundWinner();

    //checks if there are any free moves
    bool OutOfMoves();

    //shows how to play the game
    void Help();

    //tries to put player's mark on the board
    bool MakeMove(int i, char PlayerMark);

    //tries to put player's mark on the board
    bool MakeMove(int x, int y, char PlayerMark);
};


#endif //TIC_TAC_TOE_BOARD_H
