// ======================================================================
// \title  RealTimeClockDriver.cpp
// \author blakejameson
// \brief  cpp file for RealTimeClockDriver component implementation class
// ======================================================================

#include "Components/Drv/RealTimeClockDriver/RealTimeClockDriver.hpp"
#include "FpConfig.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  RealTimeClockDriver ::
    RealTimeClockDriver(const char* const compName) :
      RealTimeClockDriverComponentBase(compName)
  {

  }

  RealTimeClockDriver ::
    ~RealTimeClockDriver()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  U64 RealTimeClockDriver ::
    RealTimeClockGet_handler(NATIVE_INT_TYPE portNum)
  {
    // TODO return
  }

  void RealTimeClockDriver ::
    RealTimeClockSet_handler(
        NATIVE_INT_TYPE portNum,
        U64 currentTime
    )
  {
    // TODO
  }

}
