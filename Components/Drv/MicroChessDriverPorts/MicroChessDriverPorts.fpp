module Drv {
    @port for requesting user input
    port MoveRequest(
        startPosition: U32 @<changed to unsigned 32 bit int
        endPosition: U32
    )
    
    @port for returning the state of the board
    port BoardState(
        state: string size 20
    )
}