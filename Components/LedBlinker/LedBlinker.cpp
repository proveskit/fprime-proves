// ======================================================================
// \title  LedBlinker.cpp
// \author nateinaction
// \brief  cpp file for LedBlinker component implementation class
// ======================================================================

#include "Components/LedBlinker/LedBlinker.hpp"
#include "FpConfig.hpp"

namespace Components {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------
LedBlinker ::LedBlinker(const char* const compName) : LedBlinkerComponentBase(compName) {}

LedBlinker ::~LedBlinker() {}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

    void LedBlinker ::
        run_handler(
            const NATIVE_INT_TYPE portNum,
            NATIVE_UINT_TYPE context)
    {
        // Only perform actions when set to blinking
        if (this->blinkingState) {
            // Blink the LED
            blink();
        } else {
            // Turn off the LED
            this->neoPixelSet_out(0, Drv::NeoPixelColor(0, 0, 0));
        }

        // Report the number of blinks via a telemetry channel
        this->tlmWrite_LedBlinks(this->blinkCount);
    }

    void LedBlinker ::blink() {
        // Get interval from parameter or use default
        U32 interval = this->intervalParamOrDefault();

        // Get color from parameter or use default
        Drv::NeoPixelColor color = this->colorParamOrDefault();

        // Set the LED color or turn it off based on cycle count
        this->neoPixelSet_out(0, (this->cycleCount < (interval / 2)) ? color : Drv::NeoPixelColor(0, 0, 0));

        // Increment blink count at the start of a cycle
        this->blinkCount += (this->cycleCount == 0);

        // Increment cycle count
        this->cycleCount = (this->cycleCount + 1) % interval;
    }

    Drv::NeoPixelColor LedBlinker ::colorParamOrDefault() {
        // Read back the parameter value
        Fw::ParamValid isColorValid;
        Drv::NeoPixelColor color = this->paramGet_BLINK_COLOR(isColorValid);

        // Force color to be red when invalid or not set
        return ((Fw::ParamValid::INVALID == isColorValid) || (Fw::ParamValid::UNINIT == isColorValid)) ? Drv::NeoPixelColor(50, 0, 0) : color;
    }

    U32 LedBlinker ::intervalParamOrDefault() {
        // Read back the parameter value
        Fw::ParamValid isIntervalValid;
        U32 interval = this->paramGet_BLINK_INTERVAL(isIntervalValid);

        // Force interval to be 10 when invalid or not set
        return ((Fw::ParamValid::INVALID == isIntervalValid) || (Fw::ParamValid::UNINIT == isIntervalValid)) ? 10 : interval;
    }

    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    void LedBlinker ::BLINKING_ON_OFF_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, Fw::On blinking_state) {
        // Create a variable to represent the command response
        auto cmdResp = Fw::CmdResponse::OK;

        // Set blinking state
        this->blinkingState = blinking_state;

        // Reset cycle count
        this->cycleCount = 0;

        // Reports the state as an event
        this->log_ACTIVITY_HI_SetBlinkingState(blinking_state);

        // Report the blinking state via a telemetry channel.
        this->tlmWrite_BlinkingState(blinking_state);

        // Provide command response
        this->cmdResponse_out(opCode, cmdSeq, cmdResp);
    }

    void LedBlinker ::parameterUpdated(FwPrmIdType id) {
        switch (id)
        {
            case PARAMID_BLINK_COLOR:
                // Validate and set the color parameter on update
                this->parameterValidateColor();
                break;
            case PARAMID_BLINK_INTERVAL:
                // Validate and set the interval parameter on update
                this->parameterValidateInterval();
                break;
            default:
                FW_ASSERT(1, id); // Should never reach, invalid parameter ID
                break;
        }
    }

    void LedBlinker ::parameterValidateColor() {
        // Read back the parameter value
        Fw::ParamValid isValid;
        Drv::NeoPixelColor color = this->paramGet_BLINK_COLOR(isValid);

        // Fail if the color is invalid
        FW_ASSERT(isValid == Fw::ParamValid::VALID, isValid);

        // Log the color change
        this->log_ACTIVITY_HI_BlinkColorSet(color);

        // Report the color via a telemetry channel
        this->tlmWrite_BlinkingColor(color);
    }

    void LedBlinker ::parameterValidateInterval() {
        // Read back the parameter value
        Fw::ParamValid isValid;
        U32 interval = this->paramGet_BLINK_INTERVAL(isValid);

        // Fail if the interval is invalid
        FW_ASSERT(isValid == Fw::ParamValid::VALID, isValid);

        // Log the interval change
        this->log_ACTIVITY_HI_BlinkIntervalSet(interval);
    }
}  // namespace Components
