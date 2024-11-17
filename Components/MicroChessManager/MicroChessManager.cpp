// ======================================================================
// \title  MicroChessManager.cpp
// \author alandlt
// \brief  cpp file for MicroChessManager component implementation class
// ======================================================================

#include "Components/MicroChessManager/MicroChessManager.hpp"
#include "FpConfig.hpp"

namespace Compponents {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  MicroChessManager ::
    MicroChessManager(const char* const compName) :
      MicroChessManagerComponentBase(compName)
  {

  }

  MicroChessManager ::
    ~MicroChessManager()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void MicroChessManager ::
    Movie_Piece_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        U32 startPosition,
        U32 endPosition
    )
  {
    this->sendCommand_out(0, startPosition, endPosition);
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
