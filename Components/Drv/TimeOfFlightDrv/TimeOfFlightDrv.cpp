// ======================================================================
// \title  TimeOfFlightDrv.cpp
// \author taylorg
// \brief  cpp file for TimeOfFlightDrv component implementation class
// ======================================================================

#include "Components/Drv/TimeOfFlightDrv/TimeOfFlightDrv.hpp"
#include "FpConfig.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  TimeOfFlightDrv ::
    TimeOfFlightDrv(const char* const compName) :
      TimeOfFlightDrvComponentBase(compName),
      tof(I2CADDR)
    {
      tof.begin();
    }

  TimeOfFlightDrv ::
    ~TimeOfFlightDrv()
  {

  }

  Drv::TimeOfFlightDrv ::distanceRead_handler(NATIVE_INT_TYPE portNum) {
    uint8_t range = tof.getRange();
    return range; //idk
}
//read ambiant light value
//set calibration value

}