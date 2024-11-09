// ======================================================================
// \title  TimeOfFlightDrv.hpp
// \author taylorg
// \brief  hpp file for TimeOfFlightDrv component implementation class
// ======================================================================

#ifndef Drv_TimeOfFlightDrv_HPP
#define Drv_TimeOfFlightDrv_HPP

#include "Components/Drv/TimeOfFlightDrv/TimeOfFlightDrvComponentAc.hpp"

namespace Drv {

  class TimeOfFlightDrv :
    public TimeOfFlightDrvComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct TimeOfFlightDrv object
      TimeOfFlightDrv(
          const char* const compName //!< The component name
      );

      //! Destroy TimeOfFlightDrv object
      ~TimeOfFlightDrv();

  };

}

#endif
