// ======================================================================
// \title  CustomSX1276.hpp
// \author xf104starfighter
// \brief  hpp file for CustomSX1276 component implementation class
// ======================================================================

#ifndef Radio_CustomSX1276_HPP
#define Radio_CustomSX1276_HPP

#include "Components/Radio/CustomSX1276/CustomSX1276ComponentAc.hpp"
#include <RadioLib.h>

namespace Radio {

  class CustomSX1276 :
    public CustomSX1276ComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct CustomSX1276 object
      CustomSX1276(
          const char* const compName //!< The component name
      );

      //! Destroy CustomSX1276 object
      ~CustomSX1276();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for send
      //!
      //! Port invoked to send data out the driver
      Drv::SendStatus send_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          Fw::Buffer& sendBuffer //!< Data to send
      ) override;


      Module radio;
  };

}

#endif
