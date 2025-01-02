//
// Created by emreo on 1/2/2025.
//

#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
    for (int i = 0; i < 9; i++)
    {
        cell[i].number = i + 1;
        cell[i].gameInput = ' ';
    }
}


void TicTacToe::printBoard()
{
    std::cout << cell[0] << " | " << cell[1] << " | " << cell[2] << std::endl;
    std::cout << cell[3] << " | " << cell[4] << " | " << cell[5] << std::endl;
    std::cout << cell[6] << " | " << cell[7] << " | " << cell[8] << std::endl;

}


void TicTacToe::updateBoard(int _input, char _gameInput)
{
    cell[_input - 1].gameInput = _gameInput;
    printBoard();
    checkGameState();
}

void TicTacToe::checkGameState()
{
    for (int i = 0 ; i < 3 ; i++)
    {
        if (cell[i].gameInput == 'X' && cell[i + 3].gameInput == 'X' && cell[i + 6].gameInput == 'X')
        {
            std::cout << "Player 1 wins!" << std::endl;
            gameState = false;
            return;
        }
        if (cell[i].gameInput == 'O' && cell[i + 3].gameInput == 'O' && cell[i + 6].gameInput == 'O')
        {
            std::cout << "Player 2 wins!" << std::endl;
            gameState = false;
            return;
        }
    }

    for (int i = 0 ; i < 7 ; i += 3)
    {
        if (cell[i].gameInput == 'X' && cell[i + 1].gameInput == 'X' && cell[i + 2].gameInput == 'X')
        {
            std::cout << "Player 1 wins!" << std::endl;
            gameState = false;
            return;
        }
        if (cell[i].gameInput == 'O' && cell[i + 1].gameInput == 'O' && cell[i + 2].gameInput == 'O')
        {
            std::cout << "Player 2 wins!" << std::endl;
            gameState = false;
            return;
        }
    }

    for (int i = 0 ; i < 3 ; i += 2)
    {
        if (cell[i].gameInput == 'X' && cell[4].gameInput == 'X' && cell[8 - i].gameInput == 'X')
        {
            std::cout << "Player 1 wins!" << std::endl;
            gameState = false;
            return;
        }
        if (cell[i].gameInput == 'O' && cell[4].gameInput == 'O' && cell[8 - i].gameInput == 'O')
        {
            std::cout << "Player 2 wins!" << std::endl;
            gameState = false;
            return;
        }
    }
}
/*
    * 0 1 2
    * 3 4 5
    * 6 7 8
    */


void TicTacToe::receiveInput()
{
    if (player1 == true)
    {
        std::cout << "Player 1's turn (X)" << std::endl;

    }
    else
    {
        std::cout << "Player 2's turn (O)" << std::endl;

    }
    int input = -1;
    std::cout << "Enter a number: ";
    std::cin >> input;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }

    if (cell[input - 1].gameInput == 'X' || cell[input - 1].gameInput == 'O')
    {
        std::cout << "Invalid number!" << std::endl;
        printBoard();
        return;
    }

    if (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6 && input != 7 && input != 8 && input != 9)
    {
        std::cout << "Invalid number!" << std::endl;
        printBoard();
        return;
    }

    if (player1)
    {
        updateBoard(input, 'X');
        player1 = false;
        player2 = true;
    }
    else
    {
        updateBoard(input, 'O');
        player1 = true;
        player2 = false;
    }
}

bool TicTacToe::getGameState()
{
    return gameState;
}

std::ostream& operator<<(std::ostream& os, const TicTacToe::Cell& cell)
{
    if (cell.gameInput == ' ')
    {
        os << cell.number;
    }
    else
    {
        os << cell.gameInput;
    }
    return os;
}
