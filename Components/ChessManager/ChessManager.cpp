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
        Drv::Location startPos,
        Drv::Location endPos
    )
  {
    this->movePiece_out(0, startPos, endPos);
    Drv::displayBoardPortStrings::StringSize80 display;
    this->displayBoard_out(0, display);
    this->tlmWrite_chessBoard(display);
    this->log_ACTIVITY_HI_Piece_Moved(startPos, endPos);
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
