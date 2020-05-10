//
// Created by iliyan on 10.05.20 г..
//

#include <iostream>
#include "Board.h"


//generic constructor
Board::Board() {

    //making an empty board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = EMPTY_SPACE;
        }
    }

}

//coping constructor
Board::Board(char board1[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = board1[i][j];
        }
    }
}

//function for showing board
void Board::ShowBoard() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << '\t';
        }
        std::cout << std::endl;
    }

}

//checks if somebody won, returns winner's symbol
char Board::FoundWinner() {

    if (board[0][0] != EMPTY_SPACE) {

        //row 0
        if (board[0][0] == board[0][1] && board[0][0] == board[0][2]) {
            return board[0][0];
        }

        //col 0
        if (board[0][0] == board[1][0] && board[0][0] == board[2][0]) {
            return board[0][0];
        }

    }

    if (board[1][1] != EMPTY_SPACE) {

        //row 1
        if (board[1][1] == board[1][0] && board[1][1] == board[1][2]) {
            return board[1][1];
        }

        //col 1
        if (board[1][1] == board[0][1] && board[1][1] == board[2][1]) {
            return board[1][1];
        }

        //diagonal 00-22
        if (board[1][1] == board[0][0] && board[1][1] == board[2][2]) {
            return board[1][1];
        }

        //diagonal 02-20
        if (board[1][1] == board[0][2] && board[1][1] == board[2][0]) {
            return board[1][1];
        }

    }

    if (board[2][2] != EMPTY_SPACE) {

        //row 2
        if (board[2][2] == board[2][0] && board[2][2] == board[2][1]) {
            return board[2][2];
        }

        //col 2
        if (board[2][2] == board[0][2] && board[2][2] == board[1][2]) {
            return board[2][2];
        }

    }

    return EMPTY_SPACE;

}

//checks if there are any free moves
bool Board::OutOfMoves() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY_SPACE) {
                return false;
            };
        }
    }

    return true;

}

//shows how to play the game
void Board::Help() {

    std::cout << "To make a move in this game select one of the boxes with number 1-9\n";

    int k = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << k++ << '\t';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

};

//tries to put player's mark on the board
bool Board::MakeMove(int i, char PlayerMark) {

    int x = 0, y = 0;

    switch (i) {
        case 1: {
            x = 0;
            y = 0;
        }
            break;
        case 2: {
            x = 0;
            y = 1;
        }
            break;
        case 3: {
            x = 0;
            y = 2;
        }
            break;
        case 4: {
            x = 1;
            y = 0;
        }
            break;
        case 5: {
            x = 1;
            y = 1;
        }
            break;
        case 6: {
            x = 1;
            y = 2;
        }
            break;
        case 7: {
            x = 2;
            y = 0;
        }
            break;
        case 8: {
            x = 2;
            y = 1;
        }
            break;
        case 9: {
            x = 2;
            y = 2;
        }
            break;
        default: {
            std::cout << "Unexpected error";
        }
    }

    if (board[x][y] == EMPTY_SPACE) {
        board[x][y] = PlayerMark;
    } else {
        return false;
    }

    return true;

}

//tries to put player's mark on the board
bool Board::MakeMove(int x, int y, char PlayerMark) {

    if (board[x][y] == EMPTY_SPACE) {
        board[x][y] = PlayerMark;
    } else {
        return false;
    }

    return true;

};