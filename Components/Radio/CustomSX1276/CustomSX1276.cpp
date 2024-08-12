// ======================================================================
// \title  CustomSX1276.cpp
// \author xf104starfighter
// \brief  cpp file for CustomSX1276 component implementation class
// ======================================================================

#include "Components/Radio/CustomSX1276/CustomSX1276.hpp"
#include "FpConfig.hpp"

namespace Radio {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  CustomSX1276 ::
    CustomSX1276(const char* const compName) :
      CustomSX1276ComponentBase(compName),
      radio(
        RadioLibHal(
          1, 0, 0, 1, 1, 0
        ),
        SX1276_CS,
        SX1276_INT,
        SX1276_RST
      ) 
  {
    Serial.begin(9600);
  }

  CustomSX1276 ::
    ~CustomSX1276()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  Drv::SendStatus CustomSX1276 ::
    send_handler(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer& sendBuffer
    )
  {
    radio.transmit(sendBuffer);
  }

}
