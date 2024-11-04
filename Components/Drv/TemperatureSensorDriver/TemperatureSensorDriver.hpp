// ======================================================================
// \title  TemperatureSensorDriver.hpp
// \author jcowley04
// \brief  hpp file for TemperatureSensorDriver component implementation class
// ======================================================================

#ifndef Drv_TemperatureSensorDriver_HPP
#define Drv_TemperatureSensorDriver_HPP

#include "Components/Drv/TemperatureSensorDriver/TemperatureSensorDriverComponentAc.hpp"

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

  };

}

#endif
