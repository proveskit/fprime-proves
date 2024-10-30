module Drv {
    port RealTimeClockSet(
        currentTime: U64
    )

    port RealTimeClockGet() -> U64;
}