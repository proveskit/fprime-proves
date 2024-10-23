// ======================================================================
// \title  NeoPixelDriver.hpp
// \author nate
// \brief  hpp file for NeoPixelDriver component implementation class
// ======================================================================

#ifndef Drv_NeoPixelDriver_HPP
#define Drv_NeoPixelDriver_HPP

#include "Components/Drv/NeoPixelDriver/NeoPixelDriverComponentAc.hpp"
#include "lib/Adafruit_NeoPixel/Adafruit_NeoPixel.h"

namespace Drv {

class NeoPixelDriver : public NeoPixelDriverComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct NeoPixelDriver object
    NeoPixelDriver(const char* const compName  //!< The component name
    );

    //! Destroy NeoPixelDriver object
    ~NeoPixelDriver();

  PRIVATE:
    // ----------------------------------------------------------------------
    // Handler implementations for user-defined typed input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for neoPixelRead
    //!
    //! Port to read the current NeoPixel state.
    Drv::NeoPixelColor neoPixelRead_handler(NATIVE_INT_TYPE portNum  //!< The port number
                                    ) override;

    //! Handler implementation for neoPixelSet
    //!
    //! Port to turn modify the NeoPixel state.
    void neoPixelSet_handler(NATIVE_INT_TYPE portNum,  //!< The port number
                             const Drv::NeoPixelColor& color) override;

  PRIVATE:
    Adafruit_NeoPixel pixels;
};

}  // namespace Drv

#endif
