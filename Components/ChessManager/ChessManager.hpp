// ======================================================================
// \title  ChessManager.hpp
// \author alandlt
// \brief  hpp file for ChessManager component implementation class
// ======================================================================

#ifndef Components_ChessManager_HPP
#define Components_ChessManager_HPP

#include "Components/ChessManager/ChessManagerComponentAc.hpp"

namespace Components {

  class ChessManager :
    public ChessManagerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct ChessManager object
      ChessManager(
          const char* const compName //!< The component name
      );

      //! Destroy ChessManager object
      ~ChessManager();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command movePiece
      void movePiece_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          Drv::Location startPos,
          Drv::Location endPos
      ) override;

  };

}

#endif
