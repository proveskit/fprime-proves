// ======================================================================
// \title  RealTimeClockDriver.hpp
// \author blakejameson
// \brief  hpp file for RealTimeClockDriver component implementation class
// ======================================================================

#ifndef Drv_RealTimeClockDriver_HPP
#define Drv_RealTimeClockDriver_HPP

#include "Components/Drv/RealTimeClockDriver/RealTimeClockDriverComponentAc.hpp"
#include <lib/RV-3028_C7-Arduino_Library/src/RV-3028-C7.h>"

namespace Drv {

  class RealTimeClockDriver :
    public RealTimeClockDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct RealTimeClockDriver object
      RealTimeClockDriver(
          const char* const compName //!< The component name
      );

      //! Destroy RealTimeClockDriver object
      ~RealTimeClockDriver();

    PRIVATE:
      RV3028 RVobj;
      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for RealTimeClockGet
      U32 RealTimeClockGet_handler(
          NATIVE_INT_TYPE portNum //!< The port number
      ) override;

      //! Handler implementation for RealTimeClockSet
      Drv::RtcStatus RealTimeClockSet_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          U32 currentTime
      ) override;

  };

}

#endif
