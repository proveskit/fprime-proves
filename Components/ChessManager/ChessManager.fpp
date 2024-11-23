module Components {
    @ manages chessdriver component
    active component ChessManager {

        async command movePiece(
            startPos: Drv.Location
            endPos: Drv.Location
        )

        output port movePiece: Drv.movePiece

        output port displayBoard: Drv.displayBoard 

        telemetry chessBoard: string size 80

        event Piece_Moved (startPos: Drv.Location, endPos: Drv.Location) \
            severity activity high \
            format "Piece moved from: {} to: {}"

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

    }
}