// ======================================================================
// \title  TemperatureSensorDriver.cpp
// \author jcowley04
// \brief  cpp file for TemperatureSensorDriver component implementation class
// ======================================================================

#include "Components/Drv/TemperatureSensorDriver/TemperatureSensorDriver.hpp"
#include "FpConfig.hpp"

#define addr 0x4F
namespace Drv {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  TemperatureSensorDriver ::
    TemperatureSensorDriver(const char* const compName) :
      TemperatureSensorDriverComponentBase(compName)
  {
    sensor = Adafruit_PCT2075();
    sensor.begin(addr);
    sensor_state = Fw::On::ON;
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
    temperature = sensor.getTemperature();
  }

  void TemperatureSensorDriver ::
    PCT2075TempSensorWrite_handler(
        NATIVE_INT_TYPE portNum,
        const Fw::On& sleep_wake
    )
  {
    
  }

}
