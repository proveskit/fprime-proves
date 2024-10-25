// ======================================================================
// \title  INA219PowerMonitor.cpp
// \author davit
// \brief  cpp file for INA219PowerMonitor component implementation class
// ======================================================================

#include "Components/INA219PowerMonitor/INA219PowerMonitor.hpp"
#include "FpConfig.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  INA219PowerMonitor ::
    INA219PowerMonitor(const char* const compName) :
      INA219PowerMonitorComponentBase(compName)
  {

  }

  INA219PowerMonitor ::
    ~INA219PowerMonitor()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void INA219PowerMonitor ::
    SLEEP_WAKE_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::On sleep_wake
    )
  {
    this->sleepWake_out(0, sleep_wake);

    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
