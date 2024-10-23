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
    on_off(Fw::On::OFF),
    red(0),
    green(0),
    blue(0),
    pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800)
{
    pixels.begin();
}

NeoPixelDriver ::~NeoPixelDriver() {}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

void NeoPixelDriver ::neoPixelWrite_handler(NATIVE_INT_TYPE portNum, const Fw::On& on_off, U8 red, U8 green, U8 blue) {
    this->on_off = on_off;
    this->red = red;
    this->green = green;
    this->blue = blue;

    if (Fw::On::ON == this->on_off) {
        pixels.setPixelColor(0, pixels.Color(red, green, blue));
    } else {
        pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    }

    pixels.show();
}

}  // namespace Drv
