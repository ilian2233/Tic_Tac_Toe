//
// Created by iliyan on 10.05.20 г..
//

#ifndef TIC_TAC_TOE_MOVE_H
#define TIC_TAC_TOE_MOVE_H


//move structure
struct Move {
    int x;
    int y;
    int pos_number;

    Move(int x, int y) : x(x), y(y) {}

    Move(int posNumber) : pos_number(posNumber) {}
};


#endif //TIC_TAC_TOE_MOVE_H
