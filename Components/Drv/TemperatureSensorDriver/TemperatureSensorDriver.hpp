// ======================================================================
// \title  TemperatureSensorDriver.hpp
// \author jcowley04
// \brief  hpp file for TemperatureSensorDriver component implementation class
// ======================================================================

#ifndef Drv_TemperatureSensorDriver_HPP
#define Drv_TemperatureSensorDriver_HPP

#include "Components/Drv/TemperatureSensorDriver/TemperatureSensorDriverComponentAc.hpp"
#include "lib/Adafruit_PCT2075/Adafruit_PCT2075.h"

namespace Drv {

  class TemperatureSensorDriver :
    public TemperatureSensorDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct TemperatureSensorDriver object
      TemperatureSensorDriver(
          const char* const compName //!< The component name
      );

      //! Destroy TemperatureSensorDriver object
      ~TemperatureSensorDriver();

    PRIVATE:
      Adafruit_PCT2075 sensor;
      Fw::On sensor_state;
      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for PCT2075TempSensorRead
      //!
      //! Port to read temperature sensor data
      void PCT2075TempSensorRead_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          F32& temperature
      ) override;

      //! Handler implementation for PCT2075TempSensorWrite
      //!
      //! Port to command sensor to sleep and wake
      void PCT2075TempSensorWrite_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          const Fw::On& sleep_wake
      ) override;

  };

}

#endif
