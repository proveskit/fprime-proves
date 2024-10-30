module Drv{

    port RealTimeClockSet(
        setTime: U64
    )

    port RealTimeClockGet() -> U64
}