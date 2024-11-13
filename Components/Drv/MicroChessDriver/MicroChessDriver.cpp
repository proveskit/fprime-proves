// ======================================================================
// \title  MicroChessDriver.cpp
// \author alandlt
// \brief  cpp file for MicroChessDriver component implementation class
// ======================================================================

#include "Components/Drv/MicroChessDriver/MicroChessDriver.hpp"
#include "FpConfig.hpp"


namespace Drv {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  MicroChessDriver ::
    MicroChessDriver(const char* const compName) :
      MicroChessDriverComponentBase(compName)
  {
    board.init();
    game.init();
  }

  MicroChessDriver ::
    ~MicroChessDriver()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void MicroChessDriver ::
    BoardState_handler(
        NATIVE_INT_TYPE portNum,
        const Drv::BoardStatePortStrings::StringSize20& state
    )
  {
    // TODO
  }

  void MicroChessDriver ::
    MoveRequest_handler(
        NATIVE_INT_TYPE portNum,
        U32 startPosition,
        U32 endPosition
    )
  {
    board.set(startPosition, Empty);
    board.set(endPosition, Empty);
  }

}
