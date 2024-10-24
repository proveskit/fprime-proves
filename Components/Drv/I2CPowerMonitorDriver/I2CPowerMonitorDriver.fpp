module Drv {
    @ Wrapper for handling calls to the Adafruit_INA219 library.
    passive component I2CPowerMonitorDriver {

        @ Port to read power information.
        sync input port I2CpowerMonitorRead: Drv.I2CPowerMonitorRead

        @ Port to command the sensor to sleep and wake.
        sync input port I2CpowerMonitorWrite: I2CPowerMonitorWrite

        @ Event to report power information.
        event PowerState(bus_voltage: F32, shunt_voltage: F32, current: F32) \
            severity activity low \
            format "Voltage Bus/Shunt: {}/{}. Current: {}."

        @ Event to report information about the state of the sensor itself.
        event SensorState(state: Fw.On) \
            severity activity low \
            format "The INA219 Power Monitor is {}."

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

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

    }
}