module Components {
    @ Component to blink an LED driven by a rate group
    active component LedBlinker {

        @ Command to turn on or off the blinking LED
        async command BLINKING_ON_OFF(
            on_off: Fw.On @< Indicates whether the blinking should be on or off
            $red: U8 @< Red color value
            green: U8 @< Green color value
            blue: U8 @< Blue color value
        )

        @ Indicates we received an invalid argument.
        event InvalidBlinkArgument(badArgument: Fw.On) \
            severity warning low \
            format "Invalid Blinking Argument: {}"

        @ Reports the state we set to blinking.
        event SetBlinkingState(state: Fw.On) \
            severity activity high \
            format "Set blinking state to {}."

        @ Reports the interval that has been set
        event BlinkIntervalSet(interval: U32) \
            severity activity high \
            format "LED blink interval set to {}"
        
        @ Telemetry channel to report blinking state.
        telemetry BlinkingState: Fw.On

        @ Telemetry channel to report the LED state.
        telemetry LedBlinks: U64

        @ Blinking interval in rate group ticks
        param BLINK_INTERVAL: U32

        @ Port receiving calls from the rate group
        sync input port run: Svc.Sched

        @ Port sending calls to the GPIO driver
        output port neoPixelSet: Drv.NeoPixelWrite

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}
