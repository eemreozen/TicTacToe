//
// Created by emreo on 1/2/2025.
//

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

class TicTacToe
{
public:

    TicTacToe();

    void printBoard();

    void receiveInput();

    void updateBoard(int,char);

    bool getGameState();

    void checkGameState();

    struct Cell
    {
        int number;
        char gameInput;

        friend std::ostream& operator<<(std::ostream& os,const Cell& cell);
    };

private:



    Cell cell[9];

    bool gameState = true;

    bool player1 = true;
    bool player2 = false;
};



#endif //TICTACTOE_H
