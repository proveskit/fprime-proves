module Drv {
    port PCT2075TempSensorRead(
        ref temperature: F32
    )
    port PCT2075TempSensorWrite(
        sleep_wake: Fw.On
    )
}