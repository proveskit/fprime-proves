module Drv {
    @ Driver for the PCT2075 Temperature Sensor
    passive component TemperatureSensorDriver {

        @ Event to report current temperature
        event TemperatureState(temperature:F32) \
            severity activity low \
            format "Temperature: {}."

        event SensorState(state: Fw.On) \
            severity activity low \
            format "PCT2075 sensor is {}."
        
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
        
        @ Port to read temperature sensor data
        sync input port PCT2075TempSensorRead: PCT2075TempSensorRead
        @ Port to command sensor to sleep and wake
        sync input port PCT2075TempSensorWrite: PCT2075TempSensorWrite
        # param PARAMETER_NAME: U32

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

    }
}