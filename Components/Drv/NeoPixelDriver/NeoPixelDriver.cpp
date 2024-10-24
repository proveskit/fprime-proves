// ======================================================================
// \title  NeoPixelDriver.cpp
// \author nate
// \brief  cpp file for NeoPixelDriver component implementation class
// ======================================================================

#include "Components/Drv/NeoPixelDriver/NeoPixelDriver.hpp"
#include "FpConfig.hpp"

namespace Drv {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

#define PIN 24
#define NUMPIXELS 1

NeoPixelDriver ::NeoPixelDriver(const char* const compName) : NeoPixelDriverComponentBase(compName),
    pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800)
{
    pixels.begin();
}

NeoPixelDriver ::~NeoPixelDriver() {}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

void NeoPixelDriver ::neoPixelWrite_handler(NATIVE_INT_TYPE portNum, U8 red, U8 green, U8 blue) {
    pixels.setPixelColor(0, pixels.Color(red, green, blue));
    pixels.show();
}

}  // namespace Drv
