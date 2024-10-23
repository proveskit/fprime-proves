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
LedBlinker ::LedBlinker(const char* const compName) : LedBlinkerComponentBase(compName),
    blinking(Fw::On::OFF),
    blinkCount(0),
    cycleCount(0)
{

}

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
        Fw::ParamValid isValid;
        U32 interval = this->paramGet_BLINK_INTERVAL(isValid);

        // Force interval to be 0 when invalid or not set
        interval = ((Fw::ParamValid::INVALID == isValid) || (Fw::ParamValid::UNINIT == isValid)) ? 0 : interval;

        // Only perform actions when set to blinking
        if (this->blinking == Fw::On::ON) {
            bool transition_occurred = false;

            if (0 == this->cycleCount) {
                this->neoPixelSet_out(0, Fw::On::ON, 255, 0, 0);

                this->blinkCount = this->blinkCount + 1;
                this->tlmWrite_LedBlinks(this->blinkCount);
            } else if ((interval / 2) == this->cycleCount) {
                this->neoPixelSet_out(0, Fw::On::OFF, 0, 0, 0);
            }

            this->cycleCount = ((this->cycleCount + 1) >= interval) ? 0 : (this->cycleCount + 1);
        } else {
            this->neoPixelSet_out(0, Fw::On::OFF, 0, 0, 0);
        }
    }

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void LedBlinker ::
    BLINKING_ON_OFF_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        Fw::On on_off
    )
  {
    // Create a variable to represent the command response
    auto cmdResp = Fw::CmdResponse::OK;

    // Verify if on_off is a valid argument.
    // Note: isValid is an autogenerate helper function for enums defined in fpp.
    if(!on_off.isValid())
    {
        // Indicates we received an invalid argument.
        this->log_WARNING_LO_InvalidBlinkArgument(on_off);

        // Update command response with a validation error
        cmdResp = Fw::CmdResponse::VALIDATION_ERROR;
    }
    else
    {
        this->count = 0; // Reset count on any successful command
        this->blinking = on_off; // Update blinking state

        // Reports the state we set to blinking.
        this->log_ACTIVITY_HI_SetBlinkingState(on_off);

        // Report the blinking state via a telemetry channel.
        this->tlmWrite_BlinkingState(on_off);
    }

    // Provide command response
    this->cmdResponse_out(opCode,cmdSeq,cmdResp);
  }

  void LedBlinker ::parameterUpdated(FwPrmIdType id) {
    // Read back the parameter value
    Fw::ParamValid isValid;
    U32 interval = this->paramGet_BLINK_INTERVAL(isValid);
    // NOTE: isValid is always VALID in parameterUpdated as it was just properly set
    FW_ASSERT(isValid == Fw::ParamValid::VALID, isValid);

    // Check the parameter ID is expected
    if (PARAMID_BLINK_INTERVAL == id) {
        // Emit the blink interval set event
        this->log_ACTIVITY_HI_BlinkIntervalSet(interval);
    }
}

}  // namespace Components
