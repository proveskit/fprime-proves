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

}
