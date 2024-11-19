// ======================================================================
// \title  ChessDriver.cpp
// \author alandlt
// \brief  cpp file for ChessDriver component implementation class
// ======================================================================

#include "Components/Drv/ChessDriver/ChessDriver.hpp"
#include "FpConfig.hpp"
using namespace chess;
namespace Drv {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  ChessDriver ::
    ChessDriver(const char* const compName) :
      ChessDriverComponentBase(compName)
  {
      
  }

  ChessDriver ::
    ~ChessDriver()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  Square::underlying convert (Drv.Location pos) {
      switch (pos) {

      }
  }

  void ChessDriver ::
    movePiece_handler(
        NATIVE_INT_TYPE portNum,
        const Drv::Location& startPos,
        const Drv::Location& endPos
    )
  {
    
    Square::underlying start = convert(startPos);
    Square::underlying end = convert(endPos);
    Move m = Move::make<Move::NORMAL>(start, end);
    board::makeMove(m);
  }

}
