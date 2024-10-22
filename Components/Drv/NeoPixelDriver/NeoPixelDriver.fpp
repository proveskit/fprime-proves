module Drv {
    @ FPrime driver implmementation for Adafruit NeoPixel.
    passive component NeoPixelDriver {

        sync input port neoPixelOnOff: Drv.NeoPixelOnOff

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

    }
}
