// ======================================================================
// \title  ChessManager.cpp
// \author alandlt
// \brief  cpp file for ChessManager component implementation class
// ======================================================================

#include "Components/ChessManager/ChessManager.hpp"
#include "FpConfig.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  ChessManager ::
    ChessManager(const char* const compName) :
      ChessManagerComponentBase(compName)
  {

  }

  ChessManager ::
    ~ChessManager()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void ChessManager ::
    movePiece_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        U32 startPos,
        U32 endPos
    )
  {

    this->movePiece_out(0, startPos, endPos);
    this->tlmWrite_Move_Count(0);
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
