#include <iostream>
#include "Board.h"
#include "Move.h"

void AssignValues(unsigned long *arr, Board board1) {

    for (int i = 0; i < 9; i++) {
        arr[i] *= 2;
    }

    int arr_counter = 0;

    while (board1.FoundWinner() == EMPTY_SPACE && !board1.OutOfMoves()) {

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++, arr_counter++) {
                if (board1.board[i][j] == EMPTY_SPACE) {

                    board1.board[i][j] = PLAYER1;
                    if (board1.FoundWinner() == PLAYER1) {
                        arr[arr_counter] += 1;
                    }

                    board1.board[i][j] = PLAYER2;
                    if (board1.FoundWinner() == PLAYER2) {
                        arr[arr_counter] += 2;
                    }

                    AssignValues(arr, board1);
                }
            }
        }
    }

}

//the whole decision making behind player2
Move CalculateBestMove(char board[3][3]) {

    Board board1 = Board(board);

    unsigned long arr[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    AssignValues(arr, board1);

    int x = 0;
    int y = 0;

    int max = 0, max_i = 0;
    for (int i = 0; i < 9; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_i = i;
        }
    }

    if (max != 0) {
        return {max_i + 1};
    }

    do {

        srand(time(nullptr));
        x = rand() % 2;
        y = rand() % 2;

    } while (board1.board[x][y] != EMPTY_SPACE);

    return {x, y};

}

int main() {

    Board board = Board();

    board.Help();

    board.ShowBoard();

    do {

        int i = 0;

        do {
            std::cout << "Enter move: ";
            std::cin >> i;
        } while (i < 1 || i > 9 || !std::cin || !board.MakeMove(i, PLAYER1));

        //Bot move
        if (!board.OutOfMoves() && board.FoundWinner() == EMPTY_SPACE) {
            Move best_move = CalculateBestMove(board.board);
            if (!best_move.pos_number) {
                board.MakeMove(best_move.x, best_move.y, PLAYER2);
            } else {
                board.MakeMove(best_move.pos_number, PLAYER2);
            }
        }

        board.ShowBoard();
    } while (board.FoundWinner() == EMPTY_SPACE || board.OutOfMoves());

    if (board.FoundWinner() == EMPTY_SPACE) {
        std::cout << "the game is draw";
    } else {
        std::cout << "The winner is " << board.FoundWinner();
    }
    return 0;
}