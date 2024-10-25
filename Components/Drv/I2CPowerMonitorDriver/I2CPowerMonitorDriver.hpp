// ======================================================================
// \title  I2CPowerMonitorDriver.hpp
// \author davit
// \brief  hpp file for I2CPowerMonitorDriver component implementation class
// ======================================================================

#ifndef Drv_I2CPowerMonitorDriver_HPP
#define Drv_I2CPowerMonitorDriver_HPP

#include "Components/Drv/I2CPowerMonitorDriver/I2CPowerMonitorDriverComponentAc.hpp"
#include "lib/Adafruit_INA219/Adafruit_INA219.h"

namespace Drv {

  class I2CPowerMonitorDriver :
    public I2CPowerMonitorDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct I2CPowerMonitorDriver object
      I2CPowerMonitorDriver(
          const char* const compName //!< The component name
      );

      //! Destroy I2CPowerMonitorDriver object
      ~I2CPowerMonitorDriver();

    PRIVATE:
      Adafruit_INA219 m_sensor;
      Fw::On m_sensor_state;

      void I2CPowerMonitorRead_Handler(
        F32& bus_voltage,
        F32& shunt_voltage,
        F32& current
      );

      void I2CPowerMonitorWrite_Handler(Fw::On sensor_state);
  };

}

#endif
