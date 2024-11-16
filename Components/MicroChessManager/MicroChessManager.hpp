// ======================================================================
// \title  MicroChessManager.hpp
// \author alandlt
// \brief  hpp file for MicroChessManager component implementation class
// ======================================================================

#ifndef Compponents_MicroChessManager_HPP
#define Compponents_MicroChessManager_HPP

#include "Components/MicroChessManager/MicroChessManagerComponentAc.hpp"

namespace Compponents {

  class MicroChessManager :
    public MicroChessManagerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct MicroChessManager object
      MicroChessManager(
          const char* const compName //!< The component name
      );

      //! Destroy MicroChessManager object
      ~MicroChessManager();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command TODO
      //!
      //! TODO
      void TODO_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq //!< The command sequence number
      ) override;

  };

}

#endif
