// ======================================================================
// \title  RealTimeClockManager.hpp
// \author blakejameson
// \brief  hpp file for RealTimeClockManager component implementation class
// ======================================================================

#ifndef Components_RealTimeClockManager_HPP
#define Components_RealTimeClockManager_HPP

#include "Components/RealTimeClockManager/RealTimeClockManagerComponentAc.hpp"

namespace Components {

  class RealTimeClockManager :
    public RealTimeClockManagerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct RealTimeClockManager object
      RealTimeClockManager(
          const char* const compName //!< The component name
      );

      //! Destroy RealTimeClockManager object
      ~RealTimeClockManager();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command SET_TIME
      void SET_TIME_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          U32 timePassed
      ) override;

      void GET_TIME_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq //!< The command sequence number
      ) override;

  };

}

#endif
