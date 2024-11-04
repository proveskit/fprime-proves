// ======================================================================
// \title  TemperatureSensorDriver.cpp
// \author jcowley04
// \brief  cpp file for TemperatureSensorDriver component implementation class
// ======================================================================

#include "Components/Drv/TemperatureSensorDriver/TemperatureSensorDriver.hpp"
#include "FpConfig.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  TemperatureSensorDriver ::
    TemperatureSensorDriver(const char* const compName) :
      TemperatureSensorDriverComponentBase(compName)
  {

  }

  TemperatureSensorDriver ::
    ~TemperatureSensorDriver()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void TemperatureSensorDriver ::
    PCT2075TempSensorRead_handler(
        NATIVE_INT_TYPE portNum,
        F32& temperature
    )
  {
    // TODO
  }

  void TemperatureSensorDriver ::
    PCT2075TempSensorWrite_handler(
        NATIVE_INT_TYPE portNum,
        const Fw::On& sleep_wake
    )
  {
    // TODO
  }

}
