// ======================================================================
// \title  BroncoOreMessageHandler.hpp
// \author xf104starfighter
// \brief  hpp file for BroncoOreMessageHandler component implementation class
// ======================================================================

#ifndef Components_BroncoOreMessageHandler_HPP
#define Components_BroncoOreMessageHandler_HPP

#include "Components/BroncoOreMessageHandler/BroncoOreMessageHandlerComponentAc.hpp"

namespace Components {

  class BroncoOreMessageHandler :
    public BroncoOreMessageHandlerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct BroncoOreMessageHandler object
      BroncoOreMessageHandler(
          const char* const compName //!< The component name
      );

      //! Destroy BroncoOreMessageHandler object
      ~BroncoOreMessageHandler();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for recv_message
      //!
      //! Port for receiving messages
      void recv_message_handler(
          FwIndexType portNum, //!< The port number
          Fw::ComBuffer& data, //!< Buffer containing packet data
          U32 context //!< Call context value; meaning chosen by user
      ) override;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command MESSAGE_SEND
      //!
      //! Command to send to other satellite
      void MESSAGE_SEND_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          const Fw::CmdStringArg& message
      ) override;

  };

}

#endif
