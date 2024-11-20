module Drv {
    @ driver for chess lib
    passive component ChessDriver {

        sync input port movePiece: movePiece

        sync input port displayBoard: displayBoard
        
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
