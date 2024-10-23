module Drv {
    @ FPrime driver implmementation for Adafruit NeoPixel.
    passive component NeoPixelDriver {

        @ Port to turn modify the NeoPixel state.
        sync input port neoPixelWrite: Drv.NeoPixelWrite

        @ Event to report current NeoPixel state.
        event NeoPixelState(on_off: Fw.On, $red: U8, green: U8, blue: U8) \
            severity activity low \
            format "LED is {} with color ({}, {}, {})"

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
