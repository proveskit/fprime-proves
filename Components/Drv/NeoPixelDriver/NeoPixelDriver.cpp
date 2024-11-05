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

Drv::NeoPixelColor NeoPixelDriver ::neoPixelRead_handler(NATIVE_INT_TYPE portNum) {
    uint16_t color = pixels.getPixelColor(0);
    return Drv::NeoPixelColor((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
}

void NeoPixelDriver ::neoPixelSet_handler(NATIVE_INT_TYPE portNum, const Drv::NeoPixelColor& color) {
    pixels.setPixelColor(0, pixels.Color(color.getred(), color.getgreen(), color.getblue()));
    pixels.show();
}

}  // namespace Drv
