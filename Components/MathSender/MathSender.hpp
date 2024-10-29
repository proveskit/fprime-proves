// ======================================================================
// \title  MathSender.hpp
// \author taylorg
// \brief  hpp file for MathSender component implementation class
// ======================================================================

#ifndef MathModule_MathSender_HPP
#define MathModule_MathSender_HPP

#include "Components/MathSender/MathSenderComponentAc.hpp"

namespace MathModule {

  class MathSender :
    public MathSenderComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct MathSender object
      MathSender(
          const char* const compName //!< The component name
      );

      //! Destroy MathSender object
      ~MathSender();

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
