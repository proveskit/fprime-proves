// ======================================================================
// \title  ChessDriver.cpp
// \author alandlt
// \brief  cpp file for ChessDriver component implementation class
// ======================================================================

#include "Components/Drv/ChessDriver/ChessDriver.hpp"
#include "FpConfig.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  ChessDriver ::
    ChessDriver(const char* const compName) :
      ChessDriverComponentBase(compName)
  {
    Player* currentPlayer = NULL;
    Game::initialize();
    Board::getBoard()->display(cout);
  }

  ChessDriver ::
    ~ChessDriver()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ChessDriver ::
    movePiece_handler(
        NATIVE_INT_TYPE portNum,
        U32 startPos,
        U32 endPos
    )
  {
    Player* currentPlayer = Game::getNextPlayer();
    currentPlayer->makeMove(startPos, endPos);
    this->log_ACTIVITY_HI_displayBoard(Board::getBoard()->display(cout));// declare event in .fpp
    //this->ByteStreamSend() could use this?
  }

}
