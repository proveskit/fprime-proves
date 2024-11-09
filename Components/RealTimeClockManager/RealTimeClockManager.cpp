// ======================================================================
// \title  RealTimeClockManager.cpp
// \author blakejameson
// \brief  cpp file for RealTimeClockManager component implementation class
// ======================================================================

#include "Components/RealTimeClockManager/RealTimeClockManager.hpp"
#include "FpConfig.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  RealTimeClockManager ::
    RealTimeClockManager(const char* const compName) :
      RealTimeClockManagerComponentBase(compName)
  {

  }

  RealTimeClockManager ::
    ~RealTimeClockManager()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void RealTimeClockManager ::
    SET_TIME_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        U32 timePassed
    )
  {
    // TODO
    this->RealTimeClockDriverSet_out(0,timePassed);
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
    this->log_ACTIVITY_LO_SetTime(timePassed);
  }

}