module Drv {
    @port for requesting user input
    port MoveRequest (
        startPosition: string size 20 @<not sure if to take strings
        endPosition: string size 20
    )
    
    @port for returning the state of the board
    port BoardState (
        state: string size 20
    )
}