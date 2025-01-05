#include <iostream>
#include "TicTacToe.h"

int main()
{
    TicTacToe t;

    t.printBoard();

    while (t.getGameState())
    {

        t.receiveInput();
    }

    return 0;
}