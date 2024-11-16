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
    TODO_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
