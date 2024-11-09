module Drv {

    enum RtcStatus {
        RTC_OK = 0 @< Transaction okay
        RTC_ERR = 1 @< I2C address invalid
    }


    port RealTimeClockSet(
        currentTime: U32
    ) -> RtcStatus; 

    port RealTimeClockGet() -> U32;
}