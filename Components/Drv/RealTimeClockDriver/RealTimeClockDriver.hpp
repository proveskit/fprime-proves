// ======================================================================
// \title  RealTimeClockDriver.hpp
// \author blakejameson
// \brief  hpp file for RealTimeClockDriver component implementation class
// ======================================================================

#ifndef Drv_RealTimeClockDriver_HPP
#define Drv_RealTimeClockDriver_HPP

#include "Components/Drv/RealTimeClockDriver/RealTimeClockDriverComponentAc.hpp"

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

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for RealTimeClockGet
      U64 RealTimeClockGet_handler(
          NATIVE_INT_TYPE portNum //!< The port number
      ) override;

      //! Handler implementation for RealTimeClockSet
      void RealTimeClockSet_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          U64 currentTime
      ) override;

  };

}

#endif
