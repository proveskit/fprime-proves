// ======================================================================
// \title  I2CPowerMonitorDriver.hpp
// \author davit
// \brief  hpp file for I2CPowerMonitorDriver component implementation class
// ======================================================================

#ifndef Drv_I2CPowerMonitorDriver_HPP
#define Drv_I2CPowerMonitorDriver_HPP

#include "Components/Drv/I2CPowerMonitorDriver/I2CPowerMonitorDriverComponentAc.hpp"

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

  };

}

#endif
