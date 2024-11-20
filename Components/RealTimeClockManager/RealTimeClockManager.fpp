module Components {
    @ an active component that calls the RealTimeClockDriver
    active component RealTimeClockManager {


        async command SET_TIME(
            timePassed: U32
        )

        async command GET_TIME()

        # async command GET_TIME()
        event setTime(timePassed: U32) \
            severity activity high \
            format "Set time to {}."

        event GetTime(timePassed: U32) \
            severity activity high \
            format "The time is {}. "

        output port RealTimeClockDriverSet: Drv.RealTimeClockSet
        output port RealTimeClockDriverGet: Drv.RealTimeClockGet
        ##############################################################################
        #### Uncomment the following examples to start customizing your component ####
        ##############################################################################

        # @ Example async command
        # async command COMMAND_NAME(param_name: U32)

        # @ Example telemetry counter
        # telemetry ExampleCounter: U64

        # @ Example event
        # event ExampleStateEvent(example_state: Fw.On) severity activity high id 0 format "State set to {}"

        # @ Example port: receiving calls from the rate group
        # sync input port run: Svc.Sched

        # @ Example parameter
        # param PARAMETER_NAME: U32

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