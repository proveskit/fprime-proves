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
        const Drv::Location& startPos,
        const Drv::Location& endPos
    )
  {
    
  }

}
