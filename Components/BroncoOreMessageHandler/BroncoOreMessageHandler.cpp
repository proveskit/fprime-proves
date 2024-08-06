// ======================================================================
// \title  BroncoOreMessageHandler.cpp
// \author xf104starfighter
// \brief  cpp file for BroncoOreMessageHandler component implementation class
// ======================================================================

#include "Components/BroncoOreMessageHandler/BroncoOreMessageHandler.hpp"
#include "FpConfig.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  BroncoOreMessageHandler ::
    BroncoOreMessageHandler(const char* const compName) :
      BroncoOreMessageHandlerComponentBase(compName)
  {

  }

  BroncoOreMessageHandler ::
    ~BroncoOreMessageHandler()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void BroncoOreMessageHandler ::
    recv_message_handler(
        FwIndexType portNum,
        Fw::ComBuffer& data,
        U32 context
    )
  {
      // Fw::String message(data.getBuffAddr());
      printf("%s\n", data.getBuffAddr());
      // this->log_ACTIVITY_HI_ReportMessage(message);

    // Fw::SerializeBufferBase& incoming = fwBuffer.getSerializeRepr();
    // Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
    // Fw::CmdStringArg message;
    // FW_ASSERT(fwBuffer.getSize() != 0);
    // status = incoming.setBuffLen(fwBuffer.getSize());
    // FW_ASSERT(fwBuffer.isValid());
    // U8* bufferptr = fwBuffer.getData();
    // U32 size = fwBuffer.getSize();
    // char messageCopy[size];
    // printf("Recv Size: %u\n", size);
    // FW_ASSERT(bufferptr != nullptr);
    // printf("POtiner Address: %p\n", bufferptr);
    // printf("First 4 chars: %c \n", bufferptr[0]);
    // Fw::String stringMessage(bufferptr)
    // memcpy(messageCopy, bufferptr, size);
    // this->log_ACTIVITY_HI_ReportMessage(Fw::String("Doing the thing"));
    // Fw::String messageString(messageCopy);
    // U8* rawData = fwBuffer.getData() + sizeof(FwBuffSizeType);
    // U32 rawSize = static_cast<U32>(fwBuffer.getSize() - sizeof(FwBuffSizeType));
    // FW_ASSERT(rawSize == static_cast<U32>)
    // FW_ASSERT(status == Fw::FW_SERIALIZE_OK, static_cast<NATIVE_INT_TYPE>(status));
    // status = incoming.deserialize(bufferptr, size);
    // this->log_ACTIVITY_HI_ReportMessage();
    // deallocate_message_buffer_out(0, fwBuffer);
  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void BroncoOreMessageHandler ::
    MESSAGE_SEND_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        const Fw::CmdStringArg& message
    )
  {
    const U8* messageBuff;
    U32 size = message.length();



    Fw::ComBuffer comBuffer(reinterpret_cast<const U8*>(message.toChar()), size);

    // FW_ASSERT(message != nullptr);
    // Fw::SerializeStatus status;
    // printf("Message Length: %u \n", size);

    // U8* outgoingBuffer = outgoing.getData();
    // memcpy(outgoingBuffer, message.toChar(), size);
    // printf("POtiner Address: %p\n", outgoingBuffer);
    // printf("First 4 chars: %c%c%c%c \n", outgoingBuffer[0], outgoingBuffer[1], outgoingBuffer[2], outgoingBuffer[3]);
    // // Fw::SerializeBufferBase& serialize = outgoing.getSerializeRepr();
    // // status = serialize.serialize(messageBuff, size);
  
    // // FW_ASSERT(status == Fw::FW_SERIALIZE_OK, static_cast<NATIVE_INT_TYPE>(status));
    // // outgoing.setSize(serialize.getBuffLength());
    send_message_out(0, comBuffer, 0);
  }
}
