// ======================================================================
// \title  INA219PowerMonitor.hpp
// \author davit
// \brief  hpp file for INA219PowerMonitor component implementation class
// ======================================================================

#ifndef Components_INA219PowerMonitor_HPP
#define Components_INA219PowerMonitor_HPP

#include "Components/INA219PowerMonitor/INA219PowerMonitorComponentAc.hpp"

namespace Components {

  class INA219PowerMonitor :
    public INA219PowerMonitorComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct INA219PowerMonitor object
      INA219PowerMonitor(
          const char* const compName //!< The component name
      );

      //! Destroy INA219PowerMonitor object
      ~INA219PowerMonitor();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command SLEEP_WAKE
      void SLEEP_WAKE_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          Fw::On sleep_wake
      ) override;

  };

}

#endif
