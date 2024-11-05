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
        // Read back the parameter value
        Fw::ParamValid isIntervalValid;
        U32 interval = this->paramGet_BLINK_INTERVAL(isIntervalValid);

        // Force interval to be 0 when invalid or not set
        interval = ((Fw::ParamValid::INVALID == isIntervalValid) || (Fw::ParamValid::UNINIT == isIntervalValid)) ? 10 : interval;

        Fw::ParamValid isColorValid;
        Drv::NeoPixelColor color = this->paramGet_BLINK_COLOR(isColorValid);

        // Force color to be red when invalid or not set
        color = ((Fw::ParamValid::INVALID == isColorValid) || (Fw::ParamValid::UNINIT == isColorValid)) ? Drv::NeoPixelColor(50, 0, 0) : color;

        // Only perform actions when set to blinking
        if (this->blinkingState) {
            if (0 == this->cycleCount) {
                this->neoPixelSet_out(0, color);

                this->blinkCount = this->blinkCount + 1;
                this->tlmWrite_LedBlinks(this->blinkCount);
            } else if ((interval / 2) == this->cycleCount) {
                this->neoPixelSet_out(0, Drv::NeoPixelColor(0, 0, 0));
            }

            this->cycleCount = ((this->cycleCount + 1) >= interval) ? 0 : (this->cycleCount + 1);
        } else {
            this->neoPixelSet_out(0, Drv::NeoPixelColor(0, 0, 0));
        }
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
    //switch statement to handle different parameter IDs
    Drv::NeoPixelColor color;
    Fw::ParamValid isValid;

    switch (id)
    {
        case PARAMID_BLINK_COLOR:
            // Read back the parameter value
            color = this->paramGet_BLINK_COLOR(isValid);
            // NOTE: isValid is always VALID in parameterUpdated as it was just properly set
            FW_ASSERT(isValid == Fw::ParamValid::VALID, isValid);

            this->log_ACTIVITY_HI_BlinkColorSet(color);
            this->tlmWrite_BlinkingColor(color);

            break;
        case PARAMID_BLINK_INTERVAL:
            // Read back the parameter value
            U32 interval = this->paramGet_BLINK_INTERVAL(isValid);
            // NOTE: isValid is always VALID in parameterUpdated as it was just properly set
            FW_ASSERT(isValid == Fw::ParamValid::VALID, isValid);

            this->log_ACTIVITY_HI_BlinkIntervalSet(interval);

            break;
    }
}

}  // namespace Components
