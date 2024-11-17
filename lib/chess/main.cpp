#include <iostream>
#include "game.h"
#include "board.h"

/**
 * Main program for playing a chess game.
 */
int main ()// edited
{
    Player* currentPlayer = NULL;
    
    // initialize a chess game and display the initial state
    Game::initialize();
    Board::getBoard()->display(cout);
    int start;
    int end;
    
    // game loop in which players alternate making moves
    while(true)
    {
        currentPlayer = Game::getNextPlayer();
        while(!currentPlayer->makeMove(start, end))
        {
            cerr << "Invalid move... Try again." << endl;
        }
        Board::getBoard()->display(cout);
    }
    
    return 0;
}
