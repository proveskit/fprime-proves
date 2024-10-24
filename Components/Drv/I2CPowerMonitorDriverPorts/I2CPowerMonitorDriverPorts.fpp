module Drv {
    port I2CPowerMonitorRead(
        ref bus_voltage: F32
        ref shunt_voltage: F32
        ref current: F32
    )

    port I2CPowerMonitorWrite(
        sleep_wake: Fw.On
    )
}