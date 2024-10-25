// ======================================================================
// \title  I2CPowerMonitorDriver.cpp
// \author davit
// \brief  cpp file for I2CPowerMonitorDriver component implementation class
// ======================================================================

#include "Components/Drv/I2CPowerMonitorDriver/I2CPowerMonitorDriver.hpp"
#include "FpConfig.hpp"
#include "I2CPowerMonitorDriver.hpp"

#define addr 0x40

namespace Drv {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  I2CPowerMonitorDriver ::
    I2CPowerMonitorDriver(const char* const compName) : I2CPowerMonitorDriverComponentBase(compName),
      m_sensor_state(Fw::On::OFF)
  {
      //TODO: deal with errors
      m_sensor = Adafruit_INA219(addr);
      m_sensor.begin();
      m_sensor_state = Fw::On::ON;
  }

  I2CPowerMonitorDriver ::
    ~I2CPowerMonitorDriver()
  {

  }

  void I2CPowerMonitorDriver::I2CPowerMonitorRead_Handler(F32 &bus_voltage, F32 &shunt_voltage, F32 &current) {
    //TODO: check if the IC2 monitor is turned off. 

    bus_voltage = m_sensor.getBusVoltage_V();
    shunt_voltage = m_sensor.getShuntVoltage_mV();
    current = m_sensor.getCurrent_mA();
  }

  void I2CPowerMonitorDriver::I2CPowerMonitorWrite_Handler(Fw::On sensor_state) {
    m_sensor.powerSave(sensor_state);
  }
}
