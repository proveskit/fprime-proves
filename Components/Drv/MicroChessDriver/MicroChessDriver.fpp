module Drv {
    @ driver for MicroChess Library
    passive component MicroChessDriver {

        sync input port MoveRequest: MoveRequest

        sync input port BoardState: BoardState

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}