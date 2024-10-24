# Type definition
module Drv {
    struct Color {
        $red: U8
        green: U8
        blue: U8
    }
}

# Port definition
module Drv {
    port NeoPixelSet(color: Color)
    port NeoPixelRead -> Color
}

# Component definition
module Drv {
    @ FPrime driver implmementation for Adafruit NeoPixel.
    passive component NeoPixelDriver {
        @ Port to turn modify the NeoPixel state.
        sync input port neoPixelSet: Drv.NeoPixelSet

        @ Port to read the current NeoPixel state.
        output port neoPixelRead: Drv.NeoPixelRead

        @ Event to report current NeoPixel state.
        event NeoPixelState($red: U8, green: U8, blue: U8) \
            severity activity low \
            format "LED is set to ({}, {}, {})"

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut
    }
}
